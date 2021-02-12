using Avalonia;
using Avalonia.ReactiveUI;

namespace PlayfairCypher {
    internal static class Program {
        public static void Main(string[] args) {
            BuildAvaloniaApp().StartWithClassicDesktopLifetime(args);
        }

        private static AppBuilder BuildAvaloniaApp() {
            return AppBuilder.Configure<App>().UsePlatformDetect().LogToTrace().UseReactiveUI();
        }
    }
}