part of aes_crypt;


// Facade class for encryption and decryption methods and algorithms.
class AESCrypt {
  final _secureRandom = Random.secure();
  final _aes = _AES();

  // Creates random encryption key of [length] bytes long.
  Uint8List createKey([int length = 32]) {
    return Uint8List.fromList(List<int>.generate(length, (i) => _secureRandom.nextInt(256)));
  }

  // Creates random initialization vector.
  Uint8List createIV() => createKey(16);

  // Sets AES encryption key [key] and the initialization vector [iv].
  void setKeys(Uint8List key, Uint8List iv) => _aes.SetKeys(key, iv);

  // Encrypts binary data [data] with AES algorithm.
  //
  // ignore: non_constant_identifier_names
  Uint8List Encrypt(Uint8List data) => _aes.Encrypt(data);

  // Decrypts binary data [data] encrypted with AES algorithm.
  //
  // ignore: non_constant_identifier_names
  Uint8List Decrypt(Uint8List data) => _aes.Decrypt(data);
}
