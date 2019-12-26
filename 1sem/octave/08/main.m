#stage 6
V=33;
rand("state", V);

#stage 7
alph = char(['0':'9' 'A':'F']);
r = rand(1, 16);
ralph = r./sum(r);
save -ascii "hex.txt" ralph;

#stage 8
code = arrayfun(@(n)dec2bin(n, 4), 0:15, "UniformOutput", false);
dlmwrite('code.txt', char(code), '');

#stage 9
for i = 1:100
  msg = gen_msg(ralph, 10);
  encoded = encode_msg(msg, code);
  decoded = decode_msg(encoded, code);
  if ~strcmp(msg, decoded)
    error("[ERR] Encoded message '%s' not equal to decoded variant '%s'!", msg, decoded)
  end
end

m_len = alph_entropy(ralph);
a_len = avg_len(code, ralph);
rel_opt = m_len/a_len;

results = [a_len, m_len, min_bits(length(ralph)), rel_opt];

save -ascii "results.txt" results;