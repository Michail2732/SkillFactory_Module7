#pragma once

namespace module_7
{
	class IntegerArray
	{
		private:
			int _length{ };
			int* _array{ };
		public:
			IntegerArray() = default;
			IntegerArray(int length) throw();
			IntegerArray(const IntegerArray& container) noexcept;
			virtual ~IntegerArray() noexcept;
			int GetLength() const noexcept;
			void Resize(int newLength);
			void InsertBefore(int value, int index) throw();
			void InsertBegin(int value) noexcept;
			void InsertEnd(int value) noexcept;
			/// <summary>
			/// Возвращает результат поиска индекса элемента по его значению
			/// Возвращает -1, если не удалось найти элемент в контейнере
			/// </summary>
			/// <param name="value">значение</param>
			/// <returns></returns>
			const int IndexOf(int value) const noexcept;
			void Erase();
			void Remove(int index) throw();
			int& operator[](int index) const throw();

	};


}

