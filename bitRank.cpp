
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
        //find how many chars needed to store size times bites
        int getSize(int size) {
            return ((size-1) / 8)+1;
        }

        //check and fix mistakes in index
        void indexPreprocessing(int &index){
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
            auto charSize = getSize(size);
            //create new array of chars
            data = new char[charSize];
            this->size = charSize * 8;
        }

        bool operator[](int index){
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

        void setBitOn(int index, bool newValue){
            indexPreprocessing(index);
            //getting char
            int charIndex = index / 8;
            char *neededchar = &data[charIndex];
            //getting indent
            char indent = index % 8;

            char milde = newValue ? charMaximum : 0;

            milde = (milde) & (1<<indent);
            //changing bit
            (*neededchar) |= milde;
        }


        ~bitrank(){
           delete data;
        }
};

