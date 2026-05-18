#include <windows.h>
#include <stdbool.h>
#include "mon_tennis.h" // On inclut notre fichier de structures !

// On crée nos variables globales pour qu'elles soient accessibles partout
Raquette joueur1;
Balle balle;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // 1. Fond noir
            HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
            FillRect(hdc, &ps.rcPaint, hBrush);
            DeleteObject(hBrush);

            // 2. ON DESSINE NOTRE JEU ICI !
            dessiner_jeu(hdc, &joueur1, &balle);

            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // On initialise les positions de la raquette et de la balle
    initialiser_jeu(&joueur1, &balle);

    const char CLASS_NAME[] = "TennisWindowClass";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Mon Jeu de Tennis (GDI)", 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
        800, 600, NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    bool running = true;
    while (running) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) running = false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        InvalidateRect(hwnd, NULL, FALSE);
        Sleep(16); 
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    initialiser_jeu(&joueur1, &balle);

    const char CLASS_NAME[] = "TennisWindowClass";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Mon Jeu de Tennis (GDI)", 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
        800, 600, NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;
    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    bool running = true;
    while (running) {
        // 1. Gestion des événements de la fenêtre
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) running = false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        
        // 2. GESTION DU CLAVIER (Nouveau !)
        // Touche Z pour monter (0x5A)
        if (GetAsyncKeyState(0x5A) & 0x8000) {
            deplacer_raquette(&joueur1, -1);
        }
        // Touche S pour descendre (0x53)
        if (GetAsyncKeyState(0x53) & 0x8000) {
            deplacer_raquette(&joueur1, 1);
        }

        // 3. Redessiner l'écran
        InvalidateRect(hwnd, NULL, FALSE);
        Sleep(16); // Environ 60 FPS
    }
    return 0;
}