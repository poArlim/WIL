# 디자인 패턴 (Design Pattern)

자주 사용하는 설계 패턴을 정형화 해서 프로젝트의 상황에 맞추어 적용할 수 있도록 한 것으로 Gof(Gang of Four) 가 만든 23가지의 디자인 패턴이 가장 유명하다. 디자인 패턴은 소프트웨어 설계의 많은 경험을 토대로 하기 때문에 이를 잘 이해하고 활용한다면, 경험이 부족하더라도 좋은 소프트웨어 설계가 가능하다. 

#### 디자인 패턴의 장점
- 개발자(설계자) 간의 원활한 소통
- 소프트웨어 구조 파악 용이
- 재사용을 통한 개발 시간 단축
- 설계 변경 요청에 대한 유연한 대처

#### 대자인 패턴의 단점
- 객체지향 설계 / 구현이 필요함
- 초기 투자 비용 부담


## 생성패턴 

객체를 생성하는 것과 관련된 패턴으로, 객체의 생성과 변경이 전체 시스템에 미치는 영향을 최소화하고 코드의 유연성을 높여준다. 

- Factory Method
- [Singleton](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/singleton.md)
- Prototype
- Builder
- Abstract Factory
- Chaining


## 구조패턴 

프로그램 내의 자료구조나 인터페이스 구조 등 프로그램 구조를 설계하는 데 활용 될 수 있는 패턴으로, 많은 클래스들이 서로 의존성을 가지는 큰 규모의 시스템에서 복잡한 구조를 개발, 유지보수 하기 쉽게 해준다. 

- [Adapter](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/adapter.md)
- Composite
- Bridge
- [Decorator](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/decorator.md)
- [Facade](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/facade.md)
- Flyweight
- [Proxy](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/proxy.md)


## 행위패턴 

반복적으로 사용되는 객체들의 상호작용을 패턴화한 것으로, 클래스나 객체들이 상호작용하는 방법과 책임을 분산하는 방법을 제공한다. 독립적으로 일을 처리하고자 할 때 사용. 

- Template Method
- Interpreter
- Iterator
- [Observer](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/observer.md)
- [Strategy](https://github.com/poArlim/WIL/blob/master/Java/design-pattern/strategy.md)
- Visitor
- Chain of responsibility
- Command
- Mediator
- State
- Memento

