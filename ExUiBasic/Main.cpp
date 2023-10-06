﻿# include "stdafx.h" // OpenSiv3D v0.6.10

#include "CoordinateVisualizer.h"
#include "ItemButton.h"
#include "ItemContainer.h"
#include "TomlParametersWrapper.h"

using namespace ExUiBasic;

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{0.3, 0.3, 0.3});

	Window::SetStyle(WindowStyle::Sizable);
	Scene::SetResizeMode(ResizeMode::Keep);
	Scene::Resize(1920, 1080);
	Window::Resize(1280, 720);

	TomlParametersWrapper tomlParametersWrapper{};

	ItemContainer itemContainer{};
	CoordinateVisualizer coordinateVisualizer{};

	while (System::Update())
	{
		tomlParametersWrapper.Update();
		coordinateVisualizer.Update({.gridSpace = 40});
		itemContainer.Update();
	}
}
