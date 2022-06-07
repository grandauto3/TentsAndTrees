#pragma once
#include <memory>
#include "../game/Game.h"

namespace sf
{
	class RenderWindow;
}

class App
{
public:
	//Singleton Getter
	static App& Get()
	{
		static App a;
		return a;
	}

	void Run();

	~App() = default;
private:
	App() = default;

public:
	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

private:
	void InitApp();
	void StartApp() const;
	void UpdateApp() const;

	void RenderApp() const;


private:
	std::unique_ptr<sf::RenderWindow> window = nullptr;
	std::unique_ptr<Game> game = nullptr;
};
