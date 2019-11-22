# Функция считает кол-во выпавших орлов в логическом векторе r
function [h] = sum_heads(r) 
  h = sum(r ~= 1);
endfunction
