#stage 6
V=33;
rand("state", V);

#stage 7
alph = char([48:57 65:70]);
save -ascii "hex.txt" alph;

#stage 8
code = arrayfun(@(n)dec2bin(n, 4), 0:15, "UniformOutput", false);
dlmwrite('code.txt', char(code), '');

#stage 9
r = rand(1, 16);
ralph = r./sum(r);
for i = 1:100
  msg = gen_msg(ralph, 10);
  encoded = encode_msg(msg, code);
  decoded = decode_msg(encoded, code);
  if ~strcmp(msg, decoded)
    error("[ERR] Encoded message '%s' not equal to decoded variant '%s'!", msg, decoded)
  end
end

a_len = avg_len(code, ralph);
min_avg_len = min_bits(length(alph));
min_len = min(arrayfun(@length, code));
rel_opt = alph_entropy(ralph)/(log2(length(ralph)) * a_len);
results = [a_len, min_avg_len, min_len, rel_opt];

save -ascii "results.txt" results;