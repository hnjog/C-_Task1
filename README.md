관련 TIL : https://hnjog.github.io/c++/Week2Task1/

클래스 설명

Character
- 체력 등의 스탯과 스킬을 관리하는 캐릭터 주체
- Stat을 Base와 Enhanced로 나누어 기본 스탯과 강화 영향을 받은 스탯으로 분류
- Attack, Hit 등의 함수를 통한 대미지 계산

Skill
- 대미지 비율과 마나 소모율을 관리하는 클래스
  (구조체로 구현했어도 괜찮았을듯)

Player 
- Character를 상속받고 Inventory를 관리하는 Player 주체

Inventory
- 포션과 같은 아이템을 추가, 사용하도록 관리하는 주체

추가 파일들

Utils 
- IsNotValid, SafeDelete 등의 매크로를 별도로 저장한 헤더 파일


Enums
- Enum을 모아 놓은 헤더 파일
