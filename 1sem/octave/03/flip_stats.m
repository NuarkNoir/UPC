# Функция моделирует nexp экспериментов по подбрасыванию монетки
# nflip раз
function [s] = flip_stats(nflip, nexp) 
  s = zeros(1, nflip+1);
  for i = 1:nexp;
    r = sum_heads(coin_flip(nflip));
    s(r+1) = s(r+1) + 1;
  endfor
endfunction
