# MVC 패턴


소프트웨어가 발전하고 코드가 복잡해지다 보니 유지보수는 점점 어려워졌는데, 유지보수를 더 편하게 하기 위해 이런 저런 방식을 사용해보다가 '이렇게 코드 구성을 하니 유지보수가 편하더라!' 하는 패턴들의 규칙성을 모아 하나의 공식처럼 만든 것이 MVC 패턴이다.

즉 MVC(Model-View-Controller) 는 비지니스 로직과 화면을 구분하여 유지보수를 편하게 하는 **소프트웨어 디자인 패턴** 이다.

## 구성요소

- Model : 데이터와 비지니스 로직을 처리하는 부분
  - 사용자가 편집하길 원하는 모든 데이터를 가지고 있어야 한다.
  - View 나 Controller 에 대해서 어떤 정보도 알지 말아야 한다.
  - 변경이 일어나면, 변경 통지에 대한 처리방법을 구현해야 한다.

- View : 사용자한테 보여지는 부분
  - Model 이 가지고 있는 정보를 따로 저장해서는 안 된다.
  - Model 이나 Controller 와 같이 다른 구성요소들을 몰라야 된다.
  - 변경이 일어나면, 변경 통지에 대한 처리방법을 구현해야 한다.

- Controller : Model 과 view 를 이어주는 부분
  - Model 이나 View 에 대해서 알고 있어야 한다.
  - Model 이나 View 의 변경을 모니터링 해야 한다.

![image](https://user-images.githubusercontent.com/43959582/127988074-be8ba0e4-c31c-443e-943b-da3fe2a93e29.png)

User 가 무언가를 Controller 에게 요청을 하면 Controller 는 해당 요청을 Model 에게 전달하고, Model 은 비지니스 로직을 처리하여 요청을 수행한 후 결과를 Controller 에게 전달하고 Controller 는 이 결과를 다시 View 에게 전달하여 View 가 화면을 구성한 후 User 에게 화면으로 보여준다.


## MVC 를 지키기 위한 원칙 

1. Model 은 Controller 와 View 에 의존하지 않아야 한다. 
      - Model 내부에 Controller 와 View 에 관련된 코드가 있으면 안 된다.
2. View 는 Model 에만 의존해야 하고, Controller 에는 의존하면 안 된다.
      - View 내부에 Model 의 코드만 있을 수 있고, Controller 의 코드가 있으면 안 된다.
3. View 가 Model 로부터 데이터를 받을 때는, 사용자마다 다르게 보여주어야 하는 데이터에 대해서만 받아야 한다.
4. Controller 는 Model 과 View 에 의존해도 된다. 
      - Controller 내부에는 Model 과 View 의 코드가 있을 수 있다.
5. View 가 Model 로부터 데이터를 받을 때는, 반드시 Controller 에서 받아야 한다.


