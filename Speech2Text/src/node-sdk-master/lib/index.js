/**
 * Copyright 2014 IBM Corp. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

'use strict';

var path         = require('path');
var fs           = require('fs');
var util         = require('util');
var extend       = require('extend');
var vcapServices = require('vcap_services');
var helper       = require('./helper');
var omit         = require('object.omit');
var request      = require('request');

function encodeBase64(creds) {
  return new Buffer(creds.username + ':' + creds.password).toString('base64');
}

function createServiceAPI(serviceName) {
  return function(user_options) {
    var options = extend({}, user_options);
    var alchemy = (serviceName.indexOf('alchemy_') === 0);

    // For Alchemy we use 'v1' by default,
    // and check if `apikey` was specified.
    // We don't use VCAP_SERVICES
    if (alchemy) {
      options.alchemy = true;
      options.version = 'v1';
      options.api_key = options.apikey || options.api_key;
    } else {
      options.jar = request.jar();
    }

    // Check if 'version' was provided
    var version = options.version;
    if (typeof version === 'undefined') {
      throw new Error('Argument error: version was not specified');
    }

    // Get credentials from Bluemix
    if (options.use_vcap_services !== false) {
      var credentials = vcapServices.getCredentials(serviceName);
      if (credentials.username && credentials.password) {
        credentials.api_key = encodeBase64(credentials);
      }
      options = extend({}, options, credentials);
    }

    // Use api_key or username and password as Authorization
    var user = options.username,
      pass = options.password,
      api_key = options.api_key;

    if (!options.use_unauthenticated) {
      // Check if 'api_key' or 'username' and 'password' were provided
      if (typeof api_key === 'undefined') {
        if (typeof user === 'undefined' || typeof pass === 'undefined') {
          if (alchemy)
            throw new Error('Argument error: api_key was not specified');
          else
            throw new Error('Argument error: api_key or username and password were not specified');
        }

        // Calculate and add api_key
        options.api_key = new Buffer(user + ':' + pass).toString('base64');
      }
    }

    options = omit(options, ['version', 'username', 'password',
      'use_vcap_services', 'use_unauthenticated', 'apikey']);

    if (options.url)
      options.url = helper.stripTrailingSlash(options.url);

    try {
      // Build the path to the service file based on the service name and api version
      var servicePath = path.join(__dirname, '..', 'services', serviceName, path.basename(version));
      var Service = require(servicePath);
      var s = new Service(options);
      return Object.freeze(s);
    } catch (e) {
      if (e.code === 'MODULE_NOT_FOUND') {

        // give a clear error message for services that have been sunset, with the replacement when possible
        if (serviceName === 'search') {
          throw new Error('The search service has been replaced by retrieve_and_rank');
        }
        if (serviceName === 'message_resonance') {
          throw new Error('The message_resonance service is no longer available');
        }
        if (serviceName === 'question_and_answer') {
          console.log('The question_and_answer service is deprecated');
        }

        if (serviceName === 'tone_analyzer' && path.basename(version) === 'v1') {
          throw new Error('tone_analyzer v1 has been replaced by v2-experimental');
        }

        // for the v1.0 breaking change of requiring experimental/beta in the module name, try to offer a helpful error message.
        // https://github.com/watson-developer-cloud/node-sdk/issues/43
        var msg = 'Service %s %s not found.';
        if (fs.existsSync(path.join(__dirname, '..', 'services', serviceName, path.basename(version) + '-beta.js'))) {
          msg += ' Did you mean ' + path.basename(version) + '-beta?';
        }
        if (fs.existsSync(path.join(__dirname, '..', 'services', serviceName, path.basename(version) + '-experimental.js'))) {
          msg += ' Did you mean ' + path.basename(version) + '-experimental?';
        }

        throw new Error(util.format(msg, serviceName, version));
      } else {
        throw e;
      }
    }
  };
}

var watson = {};

[
  'concept_expansion',
  'question_and_answer',
  'relationship_extraction',
  'visual_recognition',
  'speech_to_text',
  'text_to_speech',
  'concept_insights',
  'tradeoff_analytics',
  'personality_insights',
  'natural_language_classifier',
  'authorization',
  'language_translation',
  'tone_analyzer',
  'dialog',
  'retrieve_and_rank',
  'document_conversion',
  'visual_insights',
  // deprecated
  'search',
  'message_resonance',

  // alchemy
  'alchemy_language',
  'alchemy_vision',
  'alchemy_data_news'

].forEach(function(api) {
  watson[api] = createServiceAPI(api);
});

module.exports = watson;
