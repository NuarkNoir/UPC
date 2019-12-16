## Author: nuark <nuark@DESKTOP-MJTVANB>
## Created: 2019-12-08

function emsg = encode_msg(msg, code)
  alph = ['0':'9' 'A':'F'];
  l_msg = length(msg);
  
  emsg = '';
  for i = 1:l_msg
    mask = alph == msg(i);
    if any(mask)
      emsg = strcat(emsg, code(mask));
    else
      warning("[WARN] Symbol '%s' (at pos. %d from msg) not found in alphabet", msg(i), i)
    end
  end
  emsg = emsg{1,1};
end
