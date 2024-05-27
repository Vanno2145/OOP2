#include <iostream>

using namespace std;

class Car {
	//private
	char* model;
	char* country;
	char* color;
	int year;
	double price;
	public:
		Car() {
			cout << "Construct by default." << endl;//Конструктор по умолчянию
			model = nullptr;
			country = nullptr;
			color = nullptr;
			year = 0;
			price = 0;
		}
		Car(const char* Model, const char* Country, const char* Color, int Year, double Price) {//Конструктор со всеми параметрами класса
			model = new char[strlen(Model) + 1];
			strcpy_s(model, strlen(Model) + 1, Model);

			country = new char[strlen(Country) + 1];
			strcpy_s(country, strlen(Country) + 1, Country);

			color = new char[strlen(Color) + 1];
			strcpy_s(color, strlen(Color) + 1, Color);

			year = Year;
			price = Price;
		}

		Car(const Car& first_car) {//Конструктор копирования
			model = new char[strlen(first_car.model) + 1];
			strcpy_s(model, strlen(first_car.model) + 1, first_car.model);

			country = new char[strlen(first_car.country) + 1];
			strcpy_s(country, strlen(first_car.country) + 1, first_car.country);

			color = new char[strlen(first_car.color) + 1];
			strcpy_s(color, strlen(first_car.color) + 1, first_car.color);

			year = first_car.year;
			price = first_car.price;
		}

		void Model() {//Метод инициализации модели
			cout << "Enter model: ";
			char* Model = new char[10];
			cin >> Model;
			model = new char[strlen(Model) + 1];
			strcpy_s(model, strlen(Model) + 1, Model);
		}

		void Counrty() {//Метод инициализации страны
			cout << "Enter country: ";
			char* Country = new char[10];
			cin >> Country;
			country = new char[strlen(Country) + 1];
			strcpy_s(country, strlen(Country) + 1, Country);
		}

		void Color() {//Метод инициализации цвета
			cout << "Enter color: ";
			char* Color = new char[10];
			cin >> Color;
			color = new char[strlen(Color) + 1];
			strcpy_s(color, strlen(Color) + 1, Color);
		}

		void Year() {//Метод инициализации года выпуска
			cout << "Enter year: ";
			cin >> year;
		}

		void Price() {//Метод инициализации цены
			cout << "Enter price: ";
			cin >> price;
		}

		void Show() {//Метод вывода всех полей на экран
			cout << "Model: " << model << endl
				<< "Country: " << country << endl
				<< "Color: " << color << endl
				<< "Year: " << year << endl
				<< "Price: " << price << endl;
		}

		~Car() {//Деструктор
			cout << "Destructor" << endl;
			delete[] model;
			delete[] country;
			delete[] color;
		}
};

int main() {
	Car first_car;//Создание обьекта класса Car
	

	//Инициализация всех полей
	first_car.Model();
	first_car.Counrty();
	first_car.Color();
	first_car.Year();
	first_car.Price();
	cout << endl;
	first_car.Show();//Вывод всех полей
	cout << endl;


	Car second_car = first_car;
	second_car.Show();//Инициализация одного обьекта другим в момент создания
}