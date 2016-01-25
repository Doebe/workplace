'use strict';

var watson = require('watson-developer-cloud');
var async  = require('async');

var retrieve = watson.retrieve_and_rank({
  username: 'INSERT YOUR USERNAME FOR THE SERVICE HERE',
  password: 'INSERT YOUR PASSWORD FOR THE SERVICE HERE',
  version: 'v1',
  url: 'https://gateway.watsonplatform.net/retrieve-and-rank/api'
});

var clusterId = 'INSERT YOUR CLUSTER ID HERE';
var collectionName = 'example_collection';
var configName     = 'example_config';
var configZipPath = 'examples/resources/example_solr_config.zip';

var solrClient = retrieve.createSolrClient({
  cluster_id: clusterId,
  collection_name: collectionName
});

async.series([
  function uploadConfig(done) {
    console.log('Uploading Solr config ' +  configName);
    retrieve.uploadConfig({
        cluster_id: clusterId,
        config_name: configName,
        config_zip_path: configZipPath
      },
      function(err) {
        printResponse(err, 'Error uploading Solr config: ', 'Uploaded Solr config ' + configName, done);
      });

  },

  function listConfigs(done) {
    console.log('Listing Solr configs for cluster ' + clusterId);
    retrieve.listConfigs({cluster_id: clusterId}, function(err, res) {
      printResponse(err, 'Error listing Solr configs: ', res, done);
    });
  },

  function getConfig(done) {
    console.log('Getting Solr config ' + configName);
    retrieve.getConfig({
      cluster_id: clusterId,
      config_name: configName
    }, function(err) {
      if (err) {
        console.log('Error getting config: ' + JSON.stringify(err, null, 2));
      } else {
        // Save response to a local file here
      }
      done();
    });

  },

  function createCollection(done) {
    retrieve.createCollection({
      cluster_id: clusterId,
      collection_name: collectionName,
      config_name: configName
    }, function(err, res) {
      printResponse(err, 'Error creating Solr collection: ', res, done);
    });

  },

  function listCollections(done) {
    retrieve.listCollections({cluster_id: clusterId}, function(err, res) {
      printResponse(err, 'Error listing Solr collections: ', res, done);
    });
  },

  function indexAndCommit(done) {
    console.log('Indexing a document...');
    var doc = { id : 1234, title_t : 'Hello', text_field_s: 'some text' };
    solrClient.add(doc, function(err) {
      if(err) {
        console.log('Error indexing document: ' + err);
        done();
      } else {
        console.log('Indexed a document.');
        solrClient.commit(function(err) {
          if(err) {
            console.log('Error committing change: ' + err);
          } else {
            console.log('Successfully commited changes.');
          }
          done();
        });
      }
    });
  },

  function _search(done) {
    console.log('Searching all documents.');
    var query = solrClient.createQuery();
    query.q({ '*' : '*' });
    solrClient.search(query, function(err, searchResponse) {
      if(err) {
        console.log('Error searching for documents: ' + err);
      } else {
        console.log('Found ' + searchResponse.response.numFound + ' document(s).');
        console.log('First document: ' + JSON.stringify(searchResponse.response.docs[0], null, 2));
      }
      done();
    });
  },

  function deleteCollection(done) {
    console.log('Deleting Solr collection ' + collectionName);
    retrieve.deleteCollection({
      cluster_id: clusterId,
      collection_name: collectionName
    }, function(err) {
      printResponse(err, 'Error deleting collection: ', 'Deleted Solr collection ' + collectionName, done);
    });

  },

  function deleteConfig(done) {
    console.log('Deleting Solr config ' + configName);
    retrieve.deleteConfig({
      cluster_id: clusterId,
      config_name: configName
    }, function(err) {
      printResponse(err, 'Error deleting config: ', 'Deleted Solr config ' + configName, done);
    });

  },
]);

function printResponse(error, errorMessage, response, callback) {
  if (error) {
    if (error.code) {
      console.log(errorMessage + JSON.stringify(error, null, 2));
    } else {
      console.log(errorMessage + error);
    }
  } else {
    console.log(response);
  }
  callback();
}
