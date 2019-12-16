#stage 4
V=33;
rand("state", V);

#stage 5, 6, 7
fid = fopen("results.txt", "w+");
origs = -1000 + 2000*rand(1, 100);
abserrs = [];
for i = 1:100
  x = origs(i);
  binf = print_num_bin(x, 4);
  decf = read_num_bin(binf);
  abserr = abs(x - decf);
  abserrs(end + 1) = abserr;
  fprintf(fid, "%.6f %s %.6f %.6f\n", x, binf, decf, abserr);
end
fclose(fid);

#stage 8
stats = [min(abserrs), mean(abserrs), max(abserrs)];
save -ascii "stats.txt" stats;
