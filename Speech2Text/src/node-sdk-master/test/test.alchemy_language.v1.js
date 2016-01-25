'use strict';

var assert    = require('assert');
var watson    = require('../lib/index');
var nock      = require('nock');
var qs        = require('querystring');

describe('alchemy_language', function() {

  var noop = function() {};

  // Test params
  var service = {
    api_key: 'foobar',
    url: 'http://ibm.com:80/calls',
    version: 'v1'
  };
  var apiPath = '/text/TextGetRankedNamedEntities';

  var payload = {
    text: 'sample text'
  };

  before(function() {
    nock.disableNetConnect();
  });

  after(function() {
    nock.cleanAll();
  });

  var alchemy = watson.alchemy_language(service);

  var missingParameter = function(err) {
    assert.ok((err instanceof Error) && /required parameters/.test(err));
  };

  describe('entities()', function() {

    it('should check missing parameters', function() {
      alchemy.entities({}, missingParameter);
      alchemy.entities(null, missingParameter);
      alchemy.entities(undefined, missingParameter);
      alchemy.entities({foo: 'bar'}, missingParameter);
    });

    it('should generate a valid payload', function() {
      var req = alchemy.entities(payload, noop);
      assert.equal(req.uri.href, service.url + apiPath + '?apikey=' + service.api_key);
      assert.equal(req.method, 'POST');
      assert(req.form);
      var body = new Buffer(req.body).toString('ascii');
      assert.equal(body, qs.stringify({ text: payload.text, outputMode: 'json'}));
    });

    it('should use sentiment_target if target is specified', function() {
      var req = alchemy.sentiment({text: payload.text, target:'bat'}, noop);
      var sentimenTargetPath = service.url + '/text/TextGetTargetedSentiment?apikey=' + service.api_key;
      assert.equal(req.uri.href, sentimenTargetPath);
      assert.equal(req.method, 'POST');
      assert(req.form);
      var body = new Buffer(req.body).toString('ascii');
      var expectedBody = qs.stringify({ text: payload.text,target: 'bat', outputMode: 'json'});
      assert.equal(body, expectedBody);
    });

    it('should use sentiment if target is not specified', function() {
      var req = alchemy.sentiment(payload, noop);
      var sentimenPath = service.url + '/text/TextGetTextSentiment?apikey=' + service.api_key;
      assert.equal(req.uri.href, sentimenPath);
      assert.equal(req.method, 'POST');
      assert(req.form);
      var body = new Buffer(req.body).toString('ascii');
      var expectedBody = qs.stringify({ text: payload.text, outputMode: 'json'});
      assert.equal(body, expectedBody);
    });

  });
});
