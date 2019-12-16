function s = print_num_bin(n, prec)
  neg = n < 0;
  n = abs(n);
  v = 2^prec;
  n = round(n * v);
  s = dec2bin(n);
  s = [s(1:length(s)-prec) "." s(length(s)-prec+1:end)];
  dp = strfind(s, ".");
  s = [s(1:dp) s(dp+1:dp+prec)];
  if neg
    s = ["-" s];
  end
end
