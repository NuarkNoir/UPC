function [h] = alph_entropy(P);
  P = P(P ~= 0);
  h = -sum(P.*log2(P));
endfunction;
