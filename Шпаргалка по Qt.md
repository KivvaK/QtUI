# Шпаргалка по виджетам и другим классам Qt
## QMessageBox (Всплывающее окно с сообщением)
```cpp
#include <QMessageBox>
…
QMessageBox msgb;
msgb.setText(text);
msgb.exec();
```

## QString (в примерах leInput – виджет типа QLineEdit с objectName = leInput)
1.	Преобразование из строки в число:
```cpp
QString s = ui->leInput->text();
bool ok;
double x = s.toDouble(&ok); // int x = s.toInt(&ok);
if (ok) {…}
```
2.	Преобразование из числа в строку:
```cpp
double x = 123.45;
QString s = QString::number(x, 'f', 2); // в скобках - число, формат ('g', 'G', 'f', 'F', 'e', 'E')
					// и число знаков после запятой
					// два последних параметра – не обязательны
```
3.	Преобразование из QString в const char* и обратно:
```cpp
QString s = ui->leInput->text();
const char* c_str = s.toLocal8Bit().data();
…
QString s1 = QString::fromLocal8Bit(c_str);
```
4.	Разделение строки по разделителю:
```cpp
QStringList parts = ui->leInput->text().split(" "); // здесь разделитель - пробел
for (int i = 0; i < parts.length();  i++) {
	// что-то делаем с parts[i], которые являются QString
}
```
## QListWidget (в примерах lwList – виджет типа QListWidget с objectName = lwList)
1.	Очистка:
```cpp
ui->lwList->clear();
```
2.	Добавить элемент в конец:
```cpp
ui->lwList->addItem(строка типа QString);
```
3.	Проверить, есть ли выделенный элемент:
```cpp
if (ui->lwList->selectionModel()->hasSelection())
```
4.	Номер строки, которую пользователь выделил последней:
```cpp
int index = ui->lwList->selectionModel()->currentIndex().row();
// или
int index = ui->lwFIO->currentIndex().row();
// или
int index = ui->lwList->currentRow();
```
5.	Установить/снять выделение строки:
```cpp
ui->lwList->item(индекс строки)->setSelected(true/false);
```
6.	Получить текст строки по индексу:
```cpp
QString s = ui->lwList->item(индекс)->text();
```
7.	Задать текст выделенной строки:
```cpp
ui->lwList->item(индекс)->setText(строка);
```
## QTableWidget (в примерах twTable – виджет типа QTableWidget с objectName = twTable)
1. Получить количество строк и столбцов:
```cpp
int rowCount = ui->twTable->rowCount();
int colCount = ui->twTable->columnCount();
```
2. Задать количество строк и столбцов:
```cpp
ui->twTable->setRowCount(целое число);
ui->twTable->setColumnCount(целое число);
```
3. Получить объект-содержимое ячейки на пересечении i-й строки и j-го столбца:
```cpp
QTableWidgetItem* item = ui->twTable->item(i, j);
```
*Обратите внимание, что таким образом получается указатель на объект класса QTableWidgetItem*.  
*Получить/задать его текст можно, как обычно:*
```cpp
// подразумевается, что переменная item инициализирована, как в коде выше
QString* value = item->text();	// получить текст
item->setText(строка);		// задать текст
```
**Внимание! Изначально в ячейках нет содержимого! Если пользователь туда ничего не внёс, то метод item() вернёт nullptr.**  
Но можно программно занести в ячейку объект класса QTableWidgetItem, чтобы она не была пустой:
```cpp
// создаём в ячейке новый объект item, только если его нет
if (!ui->twTable->item(i, j))
	ui->twTable->setItem(i, j, new QTableWidgetItem);
```
4. Задать режим изменения размера ячейки по ширине:
```cpp
ui->twTable->horizontalHeader()->setSectionResizeMode(режим);
```
Режим может быть: [QHeaderView::Interactive, QHeaderView::Fixed, QHeaderView::Stretch или QHeaderView::ResizeToContents](https://doc.qt.io/qt-5/qheaderview.html#ResizeMode-enum)