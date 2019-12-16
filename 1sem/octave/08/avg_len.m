## Author: nuark <nuark@DESKTOP-MJTVANB>
## Created: 2019-12-08

function l = avg_len(C, P)
  l = sum(cellfun(@length, C) .* P);
endfunction
