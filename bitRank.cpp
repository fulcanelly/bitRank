
/*
Usage:
bitrank name( size ) - to create obj of size times bits
name[index] - to obtain certain bit (in bool)
name.setBitOn(index, bool(value)) - to change bit

note: if index will more or less than size of obj code'll throw no-type error
*/
struct bitrank {

    char *data;
    int size;

    private:
        //find how many chars needed to store size times bits
        inline int toByte(int size) {
            return ((size-1) / 8)+1;
        }

        //check and fix mistakes in index
        inline void indexPreprocessing(int &index) {
            //if index negative then inverse him
            if(index < 0)
                index = size + index;
            //if index more than size - error
            if(index >= size)
                throw;
        }

    public:
        const char charMaximum = 255;

        bitrank(unsigned size = 8) {
            auto charSize = toByte(size);
            //create new array of chars
            data = new char[charSize];
            this->size = charSize * 8;
        }

        ~bitrank() {
           delete [] data;
        }

        bool operator[](int index) {
            indexPreprocessing(index);
            //getting char
            int charIndex = index / 8;
            char neededchar = data[charIndex];
            //getting indent
            int indent = index % 8;
            char diff = 1<<indent;
            //get bit
            return neededchar & diff;
        }

        void setBitAt(int index, bool newValue){
            indexPreprocessing(index);
            //getting char
            int charIndex = index / 8;
            char *neededchar = &data[charIndex];
            //getting indent(bit position)
            char indent = index % 8;
            
            char milde = newValue ? charMaximum : 0;

            milde = (milde) & (1<<indent);
            //finally changing bit
            if((*this)[index])
                (*neededchar) &= milde;
            else 
                (*neededchar) |= milde;
        }

        int resize(int newBitSize) {
            //calculating new size 
            int newByteSize = toByte(newBitSize);
            //find minimum size for copy first obj to other
            int minSize = (newByteSize * 8 < size) ? newByteSize * 8 : size;
            //changing size varible
            this->size = newByteSize * 8;
            //create new arr
            char *newArr = new char[newByteSize];

            //copy old data to new aray
            for(auto i = 0; i < minSize / 8; i++)
                newArr[i] = data[i];

            //delete old set 
            delete [] data;
            //set new
            data = newArr;
            return newByteSize;
        }

        template<class Func>
        void foreach(Func func) {
            for(int i = 0; i < size; i++)
                func(this, i, (*this)[i]);
        }
};

