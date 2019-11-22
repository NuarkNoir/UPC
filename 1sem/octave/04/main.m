# stage 1
V=33
rand("state", V)

#stage 4
c = rand(1, 10);
ralph = c./sum(c);
save -ascii "ralph.txt" ralph;

#stage 5
load -ascii "coin.txt" coin;
load -ascii "crime.txt" crime;
load -ascii "unfair.txt" unfair;
load -ascii "ventsel.txt" ventsel;

results = [
  alph_entropy(coin), alph_redundancy(coin);
  alph_entropy(crime), alph_redundancy(crime);
  alph_entropy(unfair), alph_redundancy(unfair);
  alph_entropy(ventsel), alph_redundancy(ventsel);
  alph_entropy(ralph), alph_redundancy(ralph);
]
save -ascii "results.txt" results;