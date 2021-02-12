using System;
using System.Collections.Generic;
using NUnit.Framework;
using PlayfairCypher.Models;
// ReSharper disable StringLiteralTypo

namespace PlayfairTests {
    public class Tests {
        PlayfairCrypto cryptor;
        private List<Tuple<string, string, string, string>> data;  // Tuple: keyword, text, encoded_text, decoded_text

        [SetUp]
        public void Setup() {
            cryptor = new PlayfairCrypto();
            
            data = new List<Tuple<string, string, string, string>> {
                Tuple.Create("MOTHER", "DRILL", "RAKFIZ", "DRILLX"),
                Tuple.Create("ABSOLUTE", "UNION", "TMQCPW", "UNIONX"),
                Tuple.Create("FLY", "SIMILAR", "PNNKYBSW", "SIMILARX"),
                Tuple.Create("LARGE", "VOLUME", "ZIEPOR", "VOLUME"),
                Tuple.Create("DISCIPLINE", "BEDROOM", "LASORVUF", "BEDROXOM"),
                Tuple.Create("ACUTE", "APPLIED", "COQKNAFW", "APPLIEDX"),
                Tuple.Create("COTTON", "HESITATE", "KBQLNCEK", "HESITATE"),
                Tuple.Create("PLANET", "EJECT", "AMAFCV", "EIECTX"),
                Tuple.Create("HELP", "WARM", "ZESK", "WARM"),
                Tuple.Create("SNIFF", "EXPERTISE", "DYTBTUFNDY", "EXPERTISEX"),
                Tuple.Create("VIGOROUS", "REMEDY", "IKWMHT", "REMEDY"),
                Tuple.Create("DISH", "RAINBOW", "USHLGKXY", "RAINBOWX"),
                Tuple.Create("CANDIDATE", "EMPHASIS", "FKVPDQDU", "EMPHASIS"),
                Tuple.Create("ARROW", "COPPER", "EAQVQDOV", "COPXPERX"),
                Tuple.Create("SHINE", "ILLNESS", "CRMISHIV", "ILLNESSX"),
                Tuple.Create("COUNCIL", "PROTEST", "QSIQDTRZ", "PROTESTX"),
                Tuple.Create("FUNNY", "PROGRESSIVE", "QSSBXLRZPMXC", "PROGRESXSIVE"),
                Tuple.Create("DRIFT", "RELIEF", "FBQCME", "RELIEF"),
                Tuple.Create("DEMOCRATIC", "SMILE", "QOBKMW", "SMILEX"),
                Tuple.Create("COLORFUL", "PETTY", "TAQZSZ", "PETXTY"),
                Tuple.Create("INFRASTRUCTURE", "ADVOCATE", "NKXLERUS", "ADVOCATE"),
                Tuple.Create("RADICAL", "MAINSTREAM", "KDFTTUDLDK", "MAINSTREAM"),
                Tuple.Create("TALENTED", "PROGRAM", "QSUOQLKY", "PROGRAMX"),
                Tuple.Create("FAN", "SALAD", "RNREGV", "SALADX"),
                Tuple.Create("SOUR", "SCREAM", "OBEKST", "SCREAM"),
                Tuple.Create("REWARD", "BLAME", "FIGSWV", "BLAMEX"),
                Tuple.Create("DIFFERENCE", "RESIDENT", "DRQFIRBP", "RESIDENT"),
                Tuple.Create("EXPANSION", "BIBLE", "COSRXP", "BIBLEX"),
                Tuple.Create("EXTRACT", "EXPORT", "XTQPAR", "EXPORT"),
                Tuple.Create("OVERLOOK", "FANTASY", "GKPNCPZY", "FANTASYX"),
                Tuple.Create("MAZE", "HOPE", "OTSM", "HOPE"),
                Tuple.Create("COMMENT", "PHOTOGRAPHY", "QGCACHQBQGZY", "PHOTOGRAPHYX"),
                Tuple.Create("HARD", "DISCOVER", "BGPFKZFA", "DISCOVER"),
                Tuple.Create("HOROSCOPE", "EXPERIENCED", "AWEAAQGWODAZ", "EXPERIENCEDX"),
                Tuple.Create("CHARTER", "DEMONSTRATION", "FBISMUCTRCOVLZ", "DEMONSTRATIONX"),
                Tuple.Create("ARM", "MAN", "BRLY", "MANX"),
                Tuple.Create("CREW", "RELATIONSHIP", "EWNEONTITGKO", "RELATIONSHIP"),
                Tuple.Create("MIXTURE", "RHYTHM", "BDTBDT", "RHYTHM"),
                Tuple.Create("CLAY", "STUDY", "TPCIGY", "STUDYX"),
                Tuple.Create("STATION", "POPULATION", "UTQMHOAOSE", "POPULATION"),
                Tuple.Create("MILD", "PRAY", "KUDZ", "PRAY"),
                Tuple.Create("PAT", "OVERLOOK", "VPFQIRQI", "OVERLOOK"),
                Tuple.Create("STALL", "SPECULATE", "TOFDRBLAKA", "SPECULATEX"),
                Tuple.Create("COMPUTER", "RULE", "BMWF", "RULE"),
                Tuple.Create("BARK", "RECORDING", "AFHUBFLOFY", "RECORDINGX"),
                Tuple.Create("LIABILITY", "ADOPTION", "DKPQLASG", "ADOPTION"),
                Tuple.Create("SHADOW", "CONDITION", "FARSMPMHQU", "CONDITIONX"),
                Tuple.Create("WISECRACK", "AISLE", "GAEHSY", "AISLEX"),
                Tuple.Create("CONVULSION", "KNOT", "PCCW", "KNOT"),
                Tuple.Create("DECAY", "RECOMMENDATION", "QCYMNWLCKAYSOTSA", "RECOMXMENDATIONX")
            };
        }

        [Test]
        public void EncryptionTest() {
            foreach (var tuple in data) {
                Assert.AreEqual(
                    tuple.Item3, 
                    cryptor.Encrypt(tuple.Item1, tuple.Item2)
                );
            }
        }

        [Test]
        public void DecryptionTest() {
            foreach (var tuple in data) {
                Assert.AreEqual(
                    tuple.Item4, 
                    cryptor.Decrypt(tuple.Item1, tuple.Item3)
                );
            }
        }
    }
}