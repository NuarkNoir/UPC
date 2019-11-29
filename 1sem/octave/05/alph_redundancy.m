function [r] = alph_redundancy(P);
  ent = alph_entropy(P);
  mx_ent = log2(length(P))
  r = 1 - ent/mx_ent;
endfunction;
