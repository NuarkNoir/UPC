function [n] =  read_num_code(s)
  n = bin2dec(s);
  if s(1) == '1'
    n -= 2^length(s);
  end
end