cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME MyGame)

project(${PROJECT_NAME})

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML2/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics network audio window system REQUIRED)

set(CMAKE_CXX_STANDARD 14)
add_executable(${PROJECT_NAME} main.cpp Game/Field/Cell/Cell.cpp Game/Field/Cell/Cell.h Game/Field/Field.h Game/Field/Field.cpp Game/Game.cpp Game/Game.h Tools/Iterator/Iterator.h Tools/Iterator/Iterator.cpp Tools/MyCollections/collections.cpp Tools/MyCollections/collections.h Game/Player/Player.cpp Game/Player/Player.h Game/Elements/Element.h Game/Elements/Coin.h Game/Elements/Coin.cpp Game/Elements/Mushroom.cpp Game/Elements/Mushroom.h Game/Elements/Chest.cpp Game/Elements/Chest.h Tools/AbstractFactory/AbstractFactory.h Tools/AbstractFactory/ChestFactory.cpp Tools/AbstractFactory/ChestFactory.h Tools/Strategy/BonusStrategy.h Game/Elements/ChestStrategy/Bonuses/BonusCoin.cpp Game/Elements/ChestStrategy/Bonuses/BonusCoin.h Game/Elements/ChestStrategy/Bonuses/BonusHealth.cpp Game/Elements/ChestStrategy/Bonuses/BonusHealth.h Game/Elements/ChestStrategy/Bonuses/BonusDamage.cpp Game/Elements/ChestStrategy/Bonuses/BonusDamage.h Game/Elements/ChestStrategy/Bonuses/BonusWinGame.cpp Game/Elements/ChestStrategy/Bonuses/BonusWinGame.h Game/StatusEnum.h Game/Elements/ChestStrategy/Bonuses/Bonuses.h Tools/AbstractFactory/CoinFactory.cpp Tools/AbstractFactory/CoinFactory.h Tools/AbstractFactory/MushroomFactory.cpp Tools/AbstractFactory/MushroomFactory.h Tools/Observer/Observer.h Tools/Observer/Subject.h Tools/Logger/Logger.h Tools/Logger/LogFile.cpp Tools/Logger/LogFile.h Tools/Logger/LogConsole.cpp Tools/Logger/LogConsole.h Tools/Logger/Logger.cpp Tools/Logger/Logger.h Tools/Logger/LoggerImpl.h Game/Commands/StartGame.cpp Game/Commands/StartGame.cpp Game/Commands/StartGame.h Game/Commands/MoveLeft.cpp Game/Commands/MoveLeft.h Game/Commands/MoveRight.cpp Game/Commands/MoveRight.h Game/Commands/MoveUp.cpp Game/Commands/MoveUp.h Game/Commands/MoveDown.cpp Game/Commands/MoveDown.h Game/Commands/CloseGame.cpp Game/Commands/CloseGame.cpp Game/Commands/CloseGame.h Game/Commands/Controller.cpp Game/Commands/Controller.h Tools/Command/Command.h Tools/Command/Command.h Tools/State/State.h Game/States/StateMovePlayer.h Game/States/StateMoveEnemy.h Game/States/StateMoveEnemy.cpp Game/States/StateMovePlayer.cpp Tools/SaveAndLoad/SaveAndLoad.cpp Tools/SaveAndLoad/SaveAndLoad.h Game/Commands/SaveGame.cpp Game/Commands/SaveGame.h Game/Commands/LoadGame.cpp Game/Commands/LoadGame.h UI/Menu/Menu.h Tools/Errors/InvalidFileException.h)

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

