import 'dart:typed_data';

import 'package:aes_cryptor/aes/aes_crypt.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  group("Testing correctness of AES 256 CBC implementation", () {
    test("Lots of random keys, same message", () {
      for (int i = 0; i < 1000; i++) {
        var cryptor = AESCrypt();
        cryptor.setKeys(
          cryptor.createKey(),
          cryptor.createIV(),
        );

        var message = "test string";

        var encrypted_message = cryptor.Encrypt(StringToBytes(PadString(message)));
        var decrypted_data = cryptor.Decrypt(encrypted_message);
        var decrypted_message = UnpadString(BytesToString(decrypted_data));

        expect(decrypted_message, message);
      }
    });

    test("Key as string", () {
      var key = KeyFromString("lovely day!");

      var iv = Uint8List.fromList([
        0xca, 0x94, 0xbb, 0x12, 0x93, 0x1f, 0xa7, 0xaa, 0xd7, 0xa3, 0xe7, 0xbb, 0xef, 0x21, 0xbd, 0xe6
      ]);

      var message = "test message! :D";

      var cryptor = AESCrypt();
      cryptor.setKeys(key, iv);

      var encrypted_message = cryptor.Encrypt(StringToBytes(PadString(message)));
      var decrypted_data = cryptor.Decrypt(encrypted_message);
      var decrypted_message = UnpadString(BytesToString(decrypted_data));

      expect(decrypted_message, message);
    });

    test("Russian text", () {
      var key = KeyFromString("lovely day!");

      var iv = Uint8List.fromList([
        0xca, 0x94, 0xbb, 0x12, 0x93, 0x1f, 0xa7, 0xaa, 0xd7, 0xa3, 0xe7, 0xbb, 0xef, 0x21, 0xbd, 0xe6
      ]);

      var message = "Даже на русском";

      var cryptor = AESCrypt();
      cryptor.setKeys(key, iv);

      var encrypted_message = cryptor.Encrypt(StringToBytes(PadString(message)));
      var decrypted_data = cryptor.Decrypt(encrypted_message);
      var decrypted_message = UnpadString(BytesToString(decrypted_data));

      expect(decrypted_message, message);
    });
  });
}