function [b,n] = calc_info(msg, alph, alph_p)
  l_alph = length(alph);
  l_alph_p = length(alph_p);
  l_msg = length(msg);
  if l_alph ~= l_alph_p;
    error("[ERR] length(alph) != length(alph_p) (%d != %d)", l_alph, l_alph_p)
  endif
  
  b = 0;
  for i = 1:l_msg
    flag = false;
    for j = 1:l_alph
      if msg(i) == alph(j)
        flag = true;
        b -= log(alph_p(j));
        break
      endif
    endfor
    if ~flag 
      warning("[WARN] Symbol '%s' (at pos. %d from msg) not found in alphabet", msg(i), i)
    endif
  endfor
  
  n = l_msg * log2(l_alph);
endfunction
