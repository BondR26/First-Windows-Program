#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <windowsx.h>
#include<mmsystem.h>
#include<iostream>
#include "resource.h"

#pragma comment (lib, "winmm.lib")

#define WINDOW_CLASS_NAME "MYWINCLASS1"

HINSTANCE hinstance_app = NULL;


#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000)? 1:0)
#define KEYUP(vk_code) (GetAsyncKeyState(vk_code)& 0x8000)? 0:1)

LRESULT CALLBACK WinProc(HWND handle_window, UINT msg, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT ps;
	HDC descriptor_of_device_context;
	RECT rect;


	switch (msg)
	{
	case WM_CREATE:
	{

		//PlaySound(MAKEINTRESOURCE(Create_sound), hinstance_app, SND_RESOURCE | SND_SYNC);

		//PlaySound(MAKEINTRESOURCE(Tehcno_sound), hinstance_app, SND_RESOURCE | SND_ASYNC | SND_LOOP);

		return 0;//successfull
		break;
	}
	//case WM_CHAR:
	//{/*
	//	GetClientRect(handle_window, &rect);

	//	InvalidateRect(handle_window, &rect, true);*/

	//	int ascii_code = wparam;

	//	unsigned int key_state = lparam;

	//	char buffer[CHAR_MAX];

	//	sprintf(buffer, "You pressed key -> %c, it code is -> %d, its key_state is (int bits which is ) %d ", ascii_code, ascii_code, key_state);

	//	descriptor_of_device_context = GetDC(handle_window);

	//	TextOut(descriptor_of_device_context, 0, 90, buffer, strlen(buffer));

	//	ReleaseDC(handle_window, descriptor_of_device_context);

	//	return 0;
	//	break;

	//}
	/*case WM_KEYDOWN:
	{
		int virtual_code = int(wparam);
		int key_state = int(lparam);

		

		descriptor_of_device_context = GetDC(handle_window);

		char ch = 'A';

		switch (virtual_code)
		{
		case VK_UP:
		{
			ch = VK_UP;

			break;
		}
		case VK_DOWN:
		{
			ch = VK_DOWN;
			break;
		}
		case VK_RIGHT:
		{
			ch = VK_RIGHT;
			break;
		}
		case VK_LEFT:
		{
			ch = VK_LEFT;
			break;
		}
		default:break;
		}

		char buffer[CHAR_MAX];

		sprintf(buffer, "The key %c was pressed ", ch);

		SetBkMode(descriptor_of_device_context, TRANSPARENT);

		TextOut(descriptor_of_device_context, 0, 100, buffer, strlen(buffer));

		ReleaseDC(handle_window, descriptor_of_device_context);

		

		return 0;
		break;
	}*/
	case WM_PAINT:
	{

		

		descriptor_of_device_context = BeginPaint(handle_window, &ps);

		
		EndPaint(handle_window, &ps);

		//InvalidateRect(handle_window, &rect, true);

		return 0;
		break;
	}
	case WM_ACTIVATE:
	{
		if (LOWORD(wparam) != WA_ACTIVE)
		{

		}
		else
		{

		}
		return 0;
		break;
		
	}
	case WM_MOVE:
	{

		/*int xpos = LOWORD(lparam);
		int ypos = HIWORD(lparam);

		descriptor_of_device_context = GetDC(handle_window);

		SetTextColor(descriptor_of_device_context, RGB(255, 255, 255));

		SetBkColor(descriptor_of_device_context, RGB(0, 0, 0));

		SetBkMode(descriptor_of_device_context, OPAQUE);

		char buffer[CHAR_MAX];

		sprintf(buffer, "The window was modeved to the new position = (%d, %d)", xpos, ypos);*/

		//TextOut(descriptor_of_device_context, 0, 50, buffer, strlen(buffer));

		/*ReleaseDC(handle_window, descriptor_of_device_context);*/
		return 0;
		break;
	}
	case WM_SIZE:
	{
		/*int width = LOWORD(lparam);
		int height = HIWORD(lparam);

		descriptor_of_device_context = GetDC(handle_window);

		SetTextColor(descriptor_of_device_context, RGB(rand() % 256, rand() % 256, rand() % 256, rand() % 256));
		SetBkColor(descriptor_of_device_context, RGB(0, 0, 0));
		SetBkMode(descriptor_of_device_context, TRANSPARENT);

		char buffer[CHAR_MAX];

		sprintf(buffer, "WM_SIZE called ! New Size of the WIndow = (%d, %d)", width, height);

		TextOut(descriptor_of_device_context, 0, 0, buffer, strlen(buffer));

		ReleaseDC(handle_window, descriptor_of_device_context);*/
		return 0;
		break;
	}
	case WM_ACTIVATEAPP:
	{
		break;
	}
	case WM_SIZING:
	{
		break;
	}
	case WM_CLOSE:
	{

	}
	case WM_DESTROY:
	{
		if ((MessageBox(handle_window, "You really want to exit?", "Exit", MB_OKCANCEL)) == IDOK)
		{
			PlaySound(NULL, hinstance_app, SND_PURGE);
			PostQuitMessage(0);
			return (DefWindowProc(handle_window, msg, wparam, lparam));
		}
		return 0;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wparam))
		{
		case MENU_CURSOR_GREENARROW:
		{
			SetCursor(LoadCursor(hinstance_app, MAKEINTRESOURCE(green_arrow_cursor)));
			return 0;
			break;
		}
		case MENU_CURSOR_BLUEARROW:
		{
			SetCursor(LoadCursor(hinstance_app, MAKEINTRESOURCE(blue_arrow_cursor)));
			return 0;
			break;
		}
		case MENU_ICON_WND:
		{
			
			return 0;
			break;
		}
		case MENU_ICON_LAMOT:
		{
			return 0;
			break;;
		}
		case MENU_SOUND_TECHNO:
		{
			PlaySound(MAKEINTRESOURCE(Tehcno_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_SOUND_WARP:
		{
			PlaySound(MAKEINTRESOURCE(Warp_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_SOUND_BEAM:
		{
			PlaySound(MAKEINTRESOURCE(Beam_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_SOUND_ENERGIZE:
		{
			PlaySound(MAKEINTRESOURCE(Energize_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_SOUND_CREATE:
		{
			PlaySound(MAKEINTRESOURCE(Create_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_SOUND_TELEPORT:
		{
			PlaySound(MAKEINTRESOURCE(Teleport_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);

			return 0;
			break;
		}
		case MENU_SOUND_SONIC:
		{
			PlaySound(MAKEINTRESOURCE(Sonic_sound), hinstance_app, SND_RESOURCE | SND_ASYNC);
			return 0;
			break;
		}
		case MENU_HELP:
		{
			MessageBox(handle_window, "This is section -> about", "About This Program", MB_OK | MB_ICONEXCLAMATION);
			return 0;
			break;
		}
		case MENU_EXIT:
		{

			if ((MessageBox(handle_window, "You really want to exit?", "Exit", MB_OKCANCEL | MB_ICONEXCLAMATION)) == IDOK)
			{
				PlaySound(NULL, hinstance_app, SND_PURGE);
				PostQuitMessage(0);
				return (DefWindowProc(handle_window, msg, wparam, lparam));
			}
		}
		default: break;
		}
	}
	default: break;
	}

	return (DefWindowProc(handle_window, msg, wparam, lparam));

}

WNDCLASSEX& my_own_class(HINSTANCE* hinstance, LPCSTR classname)
{

	WNDCLASSEX myclass;
	myclass.cbSize = sizeof(WNDCLASSEX);
	myclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	myclass.lpfnWndProc = WinProc;
	myclass.cbClsExtra = 0;
	myclass.cbWndExtra = 0;

	myclass.hInstance = *hinstance;

	myclass.hIcon = LoadIcon(*hinstance, MAKEINTRESOURCE(lamot_icon));

	myclass.hCursor = LoadCursor(*hinstance, IDI_APPLICATION);

	myclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);



	myclass.lpszClassName = classname;

	myclass.lpszMenuName = NULL;

	myclass.hIconSm = LoadIcon(*hinstance, MAKEINTRESOURCE(lamot_icon));

	return myclass;

}


void my_own_register(WNDCLASSEX* my_class)
{
	if (!RegisterClassEx(my_class))
	{
		std::cout << "Windows class was NOT registered\n";
	}
}

HWND& my_own_window(HINSTANCE hinstance, LPCSTR name, int location)
{
	HWND handle_window;
	if (!(handle_window = CreateWindowEx(NULL, name, "Your Basic Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0+location, 0+location, 400, 400, NULL, NULL, hinstance, NULL)))
	{
		std::cout << "WIndow was NOT created!\n";
	}

	return handle_window;
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinctance, LPSTR lpcmdline, int ncmdshow)
{
	//отримати дескриптор курсор(вказівник як файлу)
	// загрузивши дескриптор віконної процедури hinstance і використваши ресур мій курсор

	HWND handle_window;

	MSG message;

	HDC hdc;

	hinstance_app = hinstance;

	WNDCLASSEX my_class = my_own_class(&hinstance, WINDOW_CLASS_NAME);

	my_own_register(&my_class);

	handle_window = my_own_window(hinstance, WINDOW_CLASS_NAME, 0);

	HMENU menu_handle = LoadMenu(hinstance, MAKEINTRESOURCE(Main_Menu));

	SetMenu(handle_window, menu_handle);

	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);

		}

		
		//GAME_MAIN();

		hdc = GetDC(handle_window);

		SetTextColor(hdc, RGB(255, 255, 255));
		SetBkColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, OPAQUE);


		char buffer[CHAR_MAX];

		sprintf(buffer, "Current key pressed %d", KEYDOWN(VK_UP));
		TextOut(hdc, 0, 100, buffer, strlen(buffer));

		sprintf(buffer, "Current key pressed %d", KEYDOWN(VK_DOWN));
		TextOut(hdc, 0, 110, buffer, strlen(buffer));

		sprintf(buffer, "Current key pressed %d", KEYDOWN(VK_LEFT));
		TextOut(hdc, 0, 120, buffer, strlen(buffer));

		sprintf(buffer, "Current key pressed %d", KEYDOWN(VK_RIGHT));
		TextOut(hdc, 0, 130, buffer, strlen(buffer));

		ReleaseDC(handle_window, hdc);

		Sleep(100);
	}

	return(message.wParam);
}



