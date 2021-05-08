import 'dart:typed_data';

import 'package:aes_cryptor/aes/aes_crypt.dart';
import "package:flutter/material.dart";
import "package:window_size/window_size.dart";

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  const currSize = const Size(1280, 720);
  setWindowMinSize(currSize);

  runApp(App());
}

class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "AES Cryptor",
      theme: ThemeData.dark(),
      home: MainPage(),
    );
  }
}

class MainPage extends StatefulWidget {
  MainPage({Key key}) : super(key: key);

  final cryptor = AESCrypt();

  @override
  _MainPageState createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
// ignore: non_constant_identifier_names
  TextEditingController _iv_controller;
// ignore: non_constant_identifier_names
  TextEditingController _key_controller;
// ignore: non_constant_identifier_names
  TextEditingController _plain_input_controller;
// ignore: non_constant_identifier_names
  TextEditingController _cypher_input_controller;

// ignore: non_constant_identifier_names
  Uint8List aes_key, iv;

  void _generateInitialVector() {
    _cypher_input_controller.clear();

    iv = widget.cryptor.createIV();
    _iv_controller.text = _toString(iv);
    if (aes_key != null && aes_key.isNotEmpty) {
      widget.cryptor.setKeys(aes_key, iv);
    }
  }

  String _toString(Uint8List data) {
    return (data != null && data.isNotEmpty) ? BytesToHexString(data) : "";
  }

  void _showSnack(String text) {
    ScaffoldMessenger.of(context)
      ..removeCurrentSnackBar()
      ..showSnackBar(SnackBar(
        content: Text(text),
      ));
  }

  void _secretKeyChanged(String newData) {
    _cypher_input_controller.clear();

    if (newData.isEmpty) {
      aes_key = null;
      _showSnack("Cleared key");
      return;
    }

    aes_key = KeyFromString(newData);
    if (iv != null && iv.isNotEmpty) {
      widget.cryptor.setKeys(aes_key, iv);
    }
    _showSnack("Hex value of key: ${_toString(aes_key)}");
  }

  void _plainTextChanged(String newData) {
    if (iv == null || aes_key == null || iv.isEmpty || aes_key.isEmpty) {
      _showSnack("Key or IV is empty, or both.");
      return;
    }

    var encData = widget.cryptor.Encrypt(StringToBytes(PadString(newData)));
    _cypher_input_controller.text = BytesToHexString(encData);
  }

  void _cypherTextChanged(String newData) {
    if (iv == null || aes_key == null || iv.isEmpty || aes_key.isEmpty) {
      _showSnack("Key or IV is empty, or both.");
      return;
    }

    var encData = HexStringToBytes(newData);
    var decData = widget.cryptor.Decrypt(encData);
    var decStr = UnpadString(BytesToString(decData));
    _plain_input_controller.text = decStr;
  }

  @override
  void initState() {
    super.initState();
    _iv_controller = TextEditingController();
    _key_controller = TextEditingController();
    _plain_input_controller = TextEditingController();
    _cypher_input_controller = TextEditingController();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("AES Cryptor"),
      ),
      body: Container(
        padding: EdgeInsets.all(16),
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: <Widget>[
              TextFormField(
                controller: _key_controller,
                onFieldSubmitted: _secretKeyChanged,
                cursorColor: Theme.of(context).textSelectionTheme.cursorColor,
                maxLength: 32,
                decoration: InputDecoration(
                  icon: Icon(Icons.vpn_key),
                  labelText: "Secret key",
                  enabledBorder: UnderlineInputBorder(
                    borderSide: BorderSide(color: Color(0xFF6200EE)),
                  ),
                ),
              ),
              SizedBox(height: 32),
              Row(
                children: [
                  Expanded(
                    child: GestureDetector(
                      onDoubleTap: _generateInitialVector,
                      child: TextFormField(
                        controller: _iv_controller,
                        enabled: false,
                        cursorColor: Theme.of(context).textSelectionTheme.cursorColor,
                        decoration: InputDecoration(
                          icon: Icon(Icons.shield),
                          labelText: "Initial Vector",
                          errorText: "Double click, to regenerate",
                          border: OutlineInputBorder(),
                          errorStyle: TextStyle(
                            color: Theme.of(context).disabledColor, // or any other color
                          ),
                        ),
                      ),
                    ),
                  ),
                ],
              ),
              SizedBox(height: 32),
              Row(
                mainAxisSize: MainAxisSize.max,
                children: [
                  Expanded(
                    child: TextFormField(
                      keyboardType: TextInputType.multiline,
                      maxLines: 13,
                      controller: _plain_input_controller,
                      onChanged: _plainTextChanged,
                      cursorColor: Theme.of(context).textSelectionTheme.cursorColor,
                      decoration: InputDecoration(
                        labelText: "Plain text",
                        floatingLabelBehavior: FloatingLabelBehavior.always,
                        border: OutlineInputBorder(),
                      ),
                    ),
                  ),
                  SizedBox(width: 32),
                  Expanded(
                    child: TextFormField(
                      keyboardType: TextInputType.multiline,
                      maxLines: 13,
                      controller: _cypher_input_controller,
                      onChanged: _cypherTextChanged,
                      cursorColor: Theme.of(context).textSelectionTheme.cursorColor,
                      decoration: InputDecoration(
                        labelText: "Cypher text",
                        floatingLabelBehavior: FloatingLabelBehavior.always,
                        border: OutlineInputBorder(),
                      ),
                    ),
                  ),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
