관련 TIL : https://hnjog.github.io/c++/Week2Task1/

## 클래스 설명

Character
- 체력 등의 스탯과 스킬을 관리하는 캐릭터 주체
- Stat 구조체를 선언하여 Base와 Enhanced로 나누어 기본 스탯과 강화 영향을 받은 스탯으로 분류
- Attack, Hit 등의 함수를 통한 대미지 계산

Skill
- 대미지 비율과 마나 소모율을 관리하는 클래스
  (구조체로 구현했어도 괜찮았을듯)

Player 
- Character를 상속받고 Inventory를 관리하는 Player 주체

Inventory
- 포션과 같은 아이템을 추가, 사용하도록 관리하는 주체

## 추가 파일들

Utils 
- IsNotValid, SafeDelete 등의 매크로를 별도로 저장한 헤더 파일


Enums
- Enum을 모아 놓은 헤더 파일


## 트러블 슈팅 관련

<img width="2229" height="393" alt="Image" src="https://github.com/user-attachments/assets/c46fec6e-cc77-493a-95cb-19f89c01ef23" /><br>

구현하던 중, 일부 기능을 확인하려 컴파일했더니 이러한 에러가 발생하였다<br>
enum을 재선언 한 적이 없음에도<br>
해당 error 가 발생하여 매우 당황스러웠다<br>

<img width="787" height="665" alt="Image" src="https://github.com/user-attachments/assets/35f96eb3-6a62-4589-a8bf-161d7bd58f78" /><br>

얼핏보기에는 딱히 문제가 없어보였으나<br>
나중에 잘 찾아보니 중요한 전처리기가 하나 빠졌었다<br>

바로바로...<br>

```
#pragma once
```

전처리 과정에서 헤더 파일이 중복 선언되지 않도록 해주는<br>
중요한 전처리기 선언이다<br>

중요도가 높은 헤더 파일은 다양한 Include에 불려간다<br>
아래와 같은 예시에서<br>

```
C 파일
#include "a.h"

D 파일
#include "a.h"
#include "c.h"

```

만약 a 헤더에 pragma once가 선언되어 있지 않으면<br>
a 헤더의 내용이 전처리기에서 2번 써지고<br>
그로 인하여 중복 선언이나 재정의가 될 가능성이 매우 높다<br>

그렇기에 해당 전처리기문을 선언하여<br>
a 헤더가 한 번만 선언되게 하면 문제 없이 컴파일이 된다<br>

기본적으로 헤더 파일을 만들때 넣어주는 전처리기 이나<br>
Enums 파일을 만들 때, 실수로 cpp로 선언한 후 바꾸었기에<br>
해당 부분이 생략되었었다<br>