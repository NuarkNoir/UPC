function [s] = wdq(s)
  s(:, max(s) < 0.5) = 0;
endfunction
