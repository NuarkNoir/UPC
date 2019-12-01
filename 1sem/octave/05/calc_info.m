function [b,n] = calc_info(msg, alph, alph_p)
  l_alph = length(alph);
  l_alph_p = length(alph_p);
  l_msg = length(msg);
  if l_alph ~= l_alph_p;
    error("[ERR] length(alph) != length(alph_p) (%d != %d)", l_alph, l_alph_p)
  endif
  
  b = 0;
  for i = 1:l_msg
    mask = alph == msg(i);
    if any(mask)
      comp = alph_p(mask);
      b -= log2(comp);
    else
      warning("[WARN] Symbol '%s' (at pos. %d from msg) not found in alphabet", msg(i), i)
    endif
  endfor
  
  n = l_msg * log2(l_alph);
endfunction
