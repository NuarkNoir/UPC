function n = read_num_bin(s)
  neg = s(1) == "-";
  if neg
    s = substr(s, 2);
  end
  ind = find(s == '.');
  decpart = s(1:ind-1);
  floatpart = s(ind+1:end);
  n = bin2dec(decpart);
  for d = 1:length(floatpart)
    if floatpart(d) == '1'
      n = n + 2^(-d);
    end
  end
  if neg
    n = -n;
  end
end
