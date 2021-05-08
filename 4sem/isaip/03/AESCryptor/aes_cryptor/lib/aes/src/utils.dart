part of aes_crypt;

// ignore: non_constant_identifier_names
Uint8List StringToBytes(String string) {
  List<int> _data = [];

  string.codeUnits.forEach((hexB) {
    _data.addAll([
      (hexB & 0xff00) >> 8,
      hexB & 0x00ff
    ]);
  });

  return Uint8List.fromList(_data);
}

// ignore: non_constant_identifier_names
String BytesToString(Uint8List bytes) {
  assert(bytes.length % 2 == 0, "This method requires even data input!");
  String string = "";

  for (int i = 0; i < bytes.length; i += 2) {
    string += String.fromCharCode((bytes[i] << 8) + bytes[i+1]);
  }

  return string;
}

// ignore: non_constant_identifier_names
Uint8List KeyFromString(String strKey) {
  var runes = strKey.runes.toList(growable: false);
  Uint8List base = Uint8List(32);
  for (int i = 0; i < 32; i++) {
    base[i] = runes[i % runes.length];
  }
  return base;
}

// ignore: non_constant_identifier_names
String PadString(String originalStr) {
  if (originalStr.length % 16 == 0) {
    return originalStr;
  }

  var width = originalStr.length + 16 - (originalStr.length % 16);
  return originalStr.padRight(width, "`");
}

// ignore: non_constant_identifier_names
String UnpadString(String originalStr) {
  while (originalStr.endsWith("`")) {
    originalStr = originalStr.substring(0, originalStr.length-1);
  }

  return originalStr;
}

// ignore: non_constant_identifier_names
String BytesToHexString(Uint8List list) {
  StringBuffer str = StringBuffer();
  list.forEach((item) {
    str.write(item.toRadixString(16).toUpperCase().padLeft(2, '0'));
    str.write(" ");
  });
  return str.toString();
}

// ignore: non_constant_identifier_names
Uint8List HexStringToBytes(String hexString) {
  hexString = hexString.replaceAll(" ", "");
  assert(hexString.length % 2 == 0, "This method requires even data input!");
  var rxp = new RegExp(r".{2}");
  Iterable<Match> matches = rxp.allMatches(hexString);
  var bytes = matches.map((m) => int.parse(m.group(0), radix: 16)).toList();
  return Uint8List.fromList(bytes);
}
