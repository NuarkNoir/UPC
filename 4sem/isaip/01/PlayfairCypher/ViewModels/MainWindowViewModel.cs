using System;
using System.Collections.Generic;
using System.Reactive.Disposables;
using System.Text;
using Avalonia.Controls;
using PlayfairCypher.Models;
using ReactiveUI;

namespace PlayfairCypher.ViewModels {
    public class MainWindowViewModel : ReactiveObject {
        private string _keyword = "";
        private string _inputText = "";
        private string _outputText = "";
        private bool _isEncrypting = true;

        private readonly PlayfairCrypto _cryptor;

        public MainWindowViewModel() {
            _cryptor = new PlayfairCrypto();
        }

        public string Keyword {
            get => _keyword;
            set {
                this.RaiseAndSetIfChanged(ref _keyword, value.ToUpper());
                CalculateCypher();
            }
        }

        public string InputText {
            get => _inputText;
            set {
                this.RaiseAndSetIfChanged(ref _inputText, value.ToUpper());
                CalculateCypher();
            }
        }

        public string OutputText {
            get => _outputText;
            set => this.RaiseAndSetIfChanged(ref _outputText, value.ToUpper());
        }

        public bool IsEncrypting {
            get => _isEncrypting;
            set {
                this.RaiseAndSetIfChanged(ref _isEncrypting, value);
                InputText = OutputText;
            }
        }

        public void ClearForm() {
            InputText = "";
            Keyword = "";
        }

        void CalculateCypher() {
            if (InputText.Length == 0) {
                OutputText = "";
                return;
            }
            if (Keyword.Length == 0) {
                OutputText = "Error: Keyword is empty";
                return;
            }

            OutputText = IsEncrypting? _cryptor.Encrypt(Keyword.Trim(), InputText.Trim()) : _cryptor.Decrypt(Keyword.Trim(), InputText.Trim());
        }
    }
}