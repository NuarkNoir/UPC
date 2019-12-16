## Author: nuark <nuark@DESKTOP-MJTVANB>
## Created: 2019-12-08

function msg = decode_msg(emsg, code)
  alph = ['0':'9' 'A':'F'];
  msg = '';
  word = '';
  
  for c = emsg
    word(end + 1) = c;
    match = strcmp(code, word);
    if any(match)
      msg = strcat(msg, alph(match));
      word = '';
    end
  end
end
