function [s] =  print_num_code(n, len)
  s = dec2bin(mod(n, 2^len), len);
end