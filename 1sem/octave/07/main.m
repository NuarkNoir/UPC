#  33 - additive - 4
len = 4;
outf = fopen('results.txt', 'w');
fprintf(outf, 'dk %d\n', len); 
maxn = 2^(len - 1) - 1;

for n = randi([-maxn maxn], 1, 100)
  nstr = print_num_code(n, len);
  nback = read_num_code(nstr);
  fprintf(outf, '%d %s\n', n, nstr);
  
  if nback ~= n
    error("`%d` not equal to `%d` (converted from `%s`)\n", n, nback, nstr);
  end
end

fclose(outf);
