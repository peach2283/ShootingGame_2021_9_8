﻿// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <iostream>

#include "debug.h"
#include "graphic.h"
#include "Random.h"
#include "deltaTime.h"
#include "BMP.h"
#include "Input.h"
#include "GameObject.h"
#include "Sprite.h"
#include "ObjectManager.h"
#include "GameBG.h"
#include "Player.h"
#include "PlayerLaser.h"
#include "Animation.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "BoxCollider2D.h"
#include "PlayerLaserExp.h"
#include "EnemyBulletExp.h"
#include "ShipExp.h"
#include "Shield.h"
#include "EnemySpawner.h"
#include "GameManager.h"
#include "LaserItem.h"
#include "PlayerBomb.h"
#include "PlayerBombExp.h"
#include "BombItem.h"
#include "GameOver.h"
#include "Boss.h"
#include "Propeller.h"
#include "Wing.h"
#include "Gun.h"
#include "Cannon.h"
#include "Radar.h"
#include "DeadBoss.h"
#include "BossExp.h"
#include "ReturningPlayer.h"
#include "EnemyShell.h"
#include "Button.h"
#include "BTNExit.h"

#define WIDTH  480
#define HEIGHT 800

using namespace std;