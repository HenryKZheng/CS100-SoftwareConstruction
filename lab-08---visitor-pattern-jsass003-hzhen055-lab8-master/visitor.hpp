#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__


class CountVisitor{

    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;

    public:
        CountVisitor()
	{
         this->ops  = 0;
          this->rands = 0;
          this->mults = 0;
          this->divs = 0;
          this->add = 0;
          this->sub = 0;
          this->pow = 0;
        }
        
        /*Composite Pattern Visit Functions*/

        void visit_op(){this->ops++;}
        int op_count(){return this->ops;}

        void visit_rand(){this->rands++;}
        int rand_count(){return this->rands;}
        
        void visit_mult(){this->mults++;}
        int mult_count(){return this->mults;}
        
        void visit_div(){this->divs++;}
        int div_count(){return this->divs;}
        
        void visit_add(){this->add++;}
        int add_count(){return this->add;}
        
        void visit_sub(){this->sub++;}
        int sub_count(){return this->sub;}
        
        void visit_pow(){this->pow++;}
        int pow_count(){return this->pow;}
};

#endif //__COUNT_VISITOR_HPP__
