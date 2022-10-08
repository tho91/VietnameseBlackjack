cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp SFMLCard.cpp SFMLCard.h RankEnum.h SuitEnum.h
        Ranks.cpp Ranks.h Suits.cpp Suits.h Card.cpp Card.h Deck.cpp
        Deck.h CardHand.cpp CardHand.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h SFMLRank.cpp
        SFMLRank.h SFMLSuit.cpp SFMLSuit.h SFMLBackground.cpp SFMLBackground.h SFMLPokerName.cpp SFMLPokerName.h
        BlackJackInterface.cpp BlackJackInterface.h FrontPage.cpp FrontPage.h House.cpp House.h Player.cpp Player.h Button.cpp Button.h State.h States.cpp States.h StackDeck.cpp StackDeck.h BlackJackHandValue.cpp BlackJackHandValue.h BlackJackBotPlaying.cpp BlackJackBotPlaying.h BlackJackWhoWin.cpp BlackJackWhoWin.h BlackJackFaceDown.cpp BlackJackFaceDown.h BlackJackInstruction.cpp BlackJackInstruction.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()