var watson = require('watson-developer-cloud');
var fs = require('fs');
var getUserMedia = require('getusermedia');

getUserMedia({ audio: true });


var speech_to_text = watson.speech_to_text({
  username: 'c0081524-782d-46dc-a096-e82e6810dc1d',
  password: 'nZwQHkEm6HXC',
  version: 'v1'
});

var params = {
  //audio: fs.createReadStream('./test.flac'),
  content_type: 'audio/flac'
};

speech_to_text.recognize(params, function(err, transcript) {
  if (err)
    console.log(err);
  else
    console.log(JSON.stringify(transcript, null, 2));
});


