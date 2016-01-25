'use strict';

var assert = require('assert');
var watson = require('../lib/index');
var nock   = require('nock');
var qs = require('qs');

describe('tone_analyzer.v2', function() {

  var noop = function() {};

  var tone_request = {
    text: 'IBM Watson Developer Cloud'
  };
  var synonym_request = {
	  'word': 'product'
  };
  var tone_response = {
    tree: {}
  };
  var synonym_response = [ { headword: 'x' } ];

  var tone_path = '/v2/tone',
	synonym_path = '/v2/synonyms';

  var service = {
    username: 'batman',
    password: 'bruce-wayne',
    url: 'http://ibm.com:86',
    version: 'v2-experimental'
  };

  before(function() {
    nock.disableNetConnect();
    nock(service.url)
      .persist()
      .post(tone_path, tone_request.text)
      .reply(200, tone_response)
      .get(synonym_path + '?' + qs.stringify(synonym_request))
      .reply(200, synonym_response);
  });

  after(function() {
    nock.cleanAll();
  });

  var tone_analyzer = watson.tone_analyzer(service);

  var missingParameter = function(err) {
    assert.ok((err instanceof Error) && /required parameters/.test(err));
  };

  // Tone API
  it('tone API should check no parameters provided', function() {
    tone_analyzer.tone({}, missingParameter);
    tone_analyzer.tone(null, missingParameter);
    tone_analyzer.tone(undefined, missingParameter);
  });

  it('tone API should generate a valid payload with text', function() {
      var req = tone_analyzer.tone(tone_request, noop);
      var body = new Buffer(req.body).toString('ascii');
      assert.equal(req.uri.href, service.url + tone_path);
      assert.equal(body, tone_request.text);
      assert.equal(req.method, 'POST');
      assert.equal(req.headers['content-type'], 'text/plain');
  });

  it('tone API should format the response', function(done) {
    tone_analyzer.tone(tone_request, function(err, response) {
      if (err)
        done(err);
      else {
        assert.equal(JSON.stringify(response), JSON.stringify(tone_response));
        done();
      }
    });
  });

  // Synonym API

  it('synonym API should check no parameters provided', function() {
    tone_analyzer.synonym({}, missingParameter);
    tone_analyzer.synonym(null, missingParameter);
    tone_analyzer.synonym(undefined, missingParameter);
  });

  it('synonym API should generate a valid payload with content', function() {
      var req = tone_analyzer.synonym(synonym_request, noop);
      var myquery = qs.stringify(synonym_request);
      assert.equal(req.uri.href, service.url + synonym_path + '?' + myquery);
      assert.equal(req.uri.query, myquery);
      assert.equal(req.method, 'GET');
  });
  it('synonym API should format the response', function(done) {
    tone_analyzer.synonym(synonym_request, function(err, response) {
      if (err)
        done(err);
      else {
        assert.equal(JSON.stringify(response), JSON.stringify(synonym_response));
        done();
      }
    });
  });
});
