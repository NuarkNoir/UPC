# Функция моделирует подбрасывание монетки, где орёл = false
function [r] = coin_flip(N) 
  r = rand(1, N) > .5;
endfunction
