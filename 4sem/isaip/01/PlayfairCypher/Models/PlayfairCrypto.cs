// ReSharper disable StringLiteralTypo

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PlayfairCypher.Models {
    public class PlayfairCrypto {
        private static readonly HashSet<char> EnAlphabet = new("ABCDEFGHIKLMNOPQRSTUVWXYZ");
    
        public string Encrypt(string keyword, string text) {
            var keyTable = GenerateTable(keyword);
            var pairs = FormPairs(text);

            var data = new StringBuilder(32);
            
            foreach (var pair in pairs) {
                var idx1 = FindCharIndex(ref keyTable, pair[0]);
                var idx2 = FindCharIndex(ref keyTable, pair[1]);

                var x1 = idx1 / 5;  // x for rows
                var y1 = idx1 % 5;  // and y for cols
                var x2 = idx2 / 5;
                var y2 = idx2 % 5;

                char c1, c2;
                if (y1 == y2) {
                    c1 = keyTable[WrapIndex(x1 + 1), y1];
                    c2 = keyTable[WrapIndex(x2 + 1), y1];
                }
                else if (x1 == x2) {
                    c1 = keyTable[x1, WrapIndex(y1 + 1)];
                    c2 = keyTable[x1, WrapIndex(y2 + 1)];
                }
                else {
                    c1 = keyTable[x1, y2];
                    c2 = keyTable[x2, y1];
                }
                
                data.Append(c1).Append(c2);
            }

            return data.ToString();
        }
    
        public string Decrypt(string keyword, string text) {
            var keyTable = GenerateTable(keyword);
            var pairs = FormPairs(text);

            var data = new StringBuilder(32);
            
            foreach (var pair in pairs) {
                var idx1 = FindCharIndex(ref keyTable, pair[0]);
                var idx2 = FindCharIndex(ref keyTable, pair[1]);

                var x1 = idx1 / 5;  // x for rows
                var y1 = idx1 % 5;  // and y for cols
                var x2 = idx2 / 5;
                var y2 = idx2 % 5;

                char c1, c2;
                if (y1 == y2) {
                    c1 = keyTable[WrapIndex(x1 - 1), y1];
                    c2 = keyTable[WrapIndex(x2 - 1), y1];
                }
                else if (x1 == x2) {
                    c1 = keyTable[x1, WrapIndex(y1 - 1)];
                    c2 = keyTable[x1, WrapIndex(y2 - 1)];
                }
                else {
                    c1 = keyTable[x1, y2];
                    c2 = keyTable[x2, y1];
                }
                
                data.Append(c1).Append(c2);
            }

            return data.ToString();
        }

        private char[,] GenerateTable(string keyword) {
            char[,] table = new char[5,5];

            keyword = ClearKeyword(keyword);
            for (var i = 0; i < keyword.Length; i++) {
                table[i / 5,i % 5] = keyword[i];
            }

            var kwcSet = new HashSet<char>(keyword);
            var autoAlphabet = EnAlphabet.Except(kwcSet).ToList();
            for (var i = keyword.Length; i < 25; i++) {
                table[i / 5,i % 5] = autoAlphabet[i-keyword.Length];
            }

            return table;
        }

        private static string ClearKeyword(string keyword) {
            string data = "";

            keyword = keyword.Replace("J", "I");
            foreach (var kwc in keyword) {
                if (!EnAlphabet.Contains(kwc) || kwc == ' ' || data.Contains(kwc)) {
                    continue;
                }

                data += kwc;
            }

            return data;
        }

        private static int FindCharIndex(ref char[,] table, char c) {
            for (var i = 0; i < 25; i++) {
                if (table[i / 5, i % 5] == c) {
                    return i;
                }
            }

            throw new ArgumentOutOfRangeException($"Character '{c}' not fount in table");
        }

        private static List<string> FormPairs(string text) {
            List<string> data = new ();

            text = text.Replace("J", "I");
            var cc = text[0];
            for (var i = 1; i < text.Length; i++) {
                if (cc != '\0' && !EnAlphabet.Contains(cc)) {
                    cc = '\0';
                }
                if (cc == '\0') {
                    cc = text[i];
                }
                else if (cc == text[i]) {
                    data.Add("" + cc + "X");
                    cc = text[i];
                }
                else {
                    data.Add("" + cc + text[i]);
                    cc = '\0';
                }
            }

            if (cc != '\0') {
                data.Add("" + cc + "X");
            }
            
            return data;
        }

        private static int WrapIndex(int idx) {
            if (idx < 0) {
                idx += 5;
            }

            return idx % 5;
        }
    }
}