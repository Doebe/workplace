var searchTimeout = 0;


//fill and submit the form with a random example
function showExample(submit) {
  loadExample();
  if (submit)
    $('#qaForm').submit();
}

function loadQuery(query) {
  $('#questionText').val(query);
}

//fill and submit the form with a random example
function search(query, submit) {
  loadQuery(query);

  if (submit) {
    clearTimeout(searchTimeout);
    searchTimeout = setTimeout(function() {

      $('#qaForm').submit();
    }, 100);
  }
}

function speakContent(id) {
  // IE and Safari not supported disabled Mic button
  if ($('body').hasClass('ie') || $('body').hasClass('safari')) {
    $('.play').prop('disabled', true);
    $('.ie-speak .arrow-box').show();
    return;
  } else {
    $('.ie-speak .arrow-box').hide();
  }

  $('.play').removeClass('playing');
  $('#' + id).addClass('playing');

  var element = $('#response' + id);
  var text = element.html();
  speech.speak(text);
}

$('#qaForm').submit(function(e) {
  var form = $(this);
  $.ajax({
    url: form.attr('action'),
    type: form.attr('method'),
    data: form.serialize(),
    success: function(response) {
      $('#result').html(response);

      $('#result').find('.play').click(function(event) {
        var target = $(event.target);
        if (target.hasClass('playing')) {
          target.removeClass('playing');
          speech.stop();
        } else {
          speakContent(event.target.getAttribute('id'));
        }
      });
    }
  });
  return false;
});

$('#listen').click(function(e) {
  switch (speechState) {
    case 'listening':
      speech.recognizeAbort();
      setButtonState('default');
      break;
    case 'speaking':
      speech.stop();
      $('.play').removeClass('playing');
      setButtonState('default');
      break;
    default:
      speech.recognize();
      setButtonState('listening');
      $('#listen').blur();
      break;
  }

  return false;
});

var speechState = '';

function setButtonState(state) {
  console.log(state);
  var button = $('#listen');
  speechState = state;

  button.removeClass('listen').removeClass('stop').removeClass('playing');

  switch (state) {
    case 'listening':
      button.addClass('stop');
      break;
    case 'speaking':
      button.addClass('playing');
      break;
    default:
      button.addClass('listen');
      break;
  }
}

$(document).ready(function() {
  // IE and Safari not supported disabled Mic button
  if ($('body').hasClass('ie') || $('body').hasClass('safari')) {
    $('#listen').prop('disabled', true);
    $('.ie-speak .arrow-box').show();
  } else {
    $('.ie-speak .arrow-box').hide();
  }

})