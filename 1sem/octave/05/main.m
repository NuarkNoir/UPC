#stage 3
V=33
rand("state", V)

#stage 4
alph = char([48:57 65:70]);
r = rand(1, 16);
ralph = r./sum(r);
save -ascii "ralph.txt" ralph;

#stage 5
h = alph_entropy(ralph);
r = alph_redundancy(ralph);

#stage 6
msg = gen_msg(ralph, 100);
dlmwrite("msg.txt", msg, '');

#stage 7
[b, n] = calc_info(msg, alph, ralph);

#stage 8
avg_b = b / length(msg);

#stage 9
results = [b, n, avg_b, h, r]
save -ascii "results.txt" results;
