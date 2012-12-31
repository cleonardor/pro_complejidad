#include "constraintsmanager.h"
#include <QFile>
#include <QTextStream>

ConstraintsManager::ConstraintsManager(int m, QVector<City *> *cities)
{
    this->m = m;
    this->cities = cities;
    this->amountConstraints = 11 + 17*cities->size() + 1;//1 porque se usa la última fila para la función objetivo
    this->amountVariables = 4 + 5*cities->size() + 1;//1 porque se usa para rhs, en realidad no es una variable
    this->inequalities = new std::string[this->amountConstraints-1];
    this->columnNumber = new int[this->amountVariables-1];
    this->constraints = new double*[this->amountConstraints];
    for(int i=0;i<this->amountConstraints;i++)
    {
        this->constraints[i] = new double[this->amountVariables];
    }

    for(int i=0;i<this->amountConstraints;i++)
    {
        for(int j=0;j<this->amountVariables;j++)
        {
            this->constraints[i][j] = 0;
        }
    }

    for(int i=1;i<=this->amountVariables-1;i++)
    {
        this->columnNumber[i-1] = i;
    }
}

ConstraintsManager::~ConstraintsManager()
{
    for(int i=0;i<this->amountConstraints;i++)
    {
        delete this->constraints[i];
        this->constraints[i] = 0;
    }
    delete this->constraints;
    //delete inequalities; si hago esto muere por algún motivo que desconozco
    delete columnNumber;

    this->constraints = 0;
    this->cities = 0;
    //this->inequalities = 0;
    this->columnNumber = 0;
}

void ConstraintsManager::buildContraints()
{
    int n = this->cities->size();
    int constraintNumber = 0, constant = this->amountVariables-1;//-1 por ser indice de matriz
    int Dxi=0, Dyi=n, Sxi=2*n, Syi=3*n, ci=4*n, Dx=5*n, Dy=5*n+1, Ax=5*n+2, Ay=5*n+3;

    //Ax - sum[i=1][n]{cxi*ci} - Dx <= 0
    this->constraints[constraintNumber][Ax] = 1;
    this->constraints[constraintNumber][Dx] = -1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = "<=";
    for(int i=0;i<n;i++)
    {
        this->constraints[constraintNumber][ci+i] = -this->cities->at(i)->getCoorX();
    }

    //-Ax + sum[i=1][n]{cxi*ci} - Dx <= 0
    constraintNumber++;
    this->constraints[constraintNumber][Ax] = -1;
    this->constraints[constraintNumber][Dx] = -1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = "<=";
    for(int i=0;i<n;i++)
    {
        this->constraints[constraintNumber][ci+i] = this->cities->at(i)->getCoorX();
    }

    //Ay - sum[i=1][n]{cyi*ci} - Dy <= 0
    constraintNumber++;
    this->constraints[constraintNumber][Ay] = 1;
    this->constraints[constraintNumber][Dy] = -1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = "<=";
    for(int i=0;i<n;i++)
    {
        this->constraints[constraintNumber][ci+i] = -this->cities->at(i)->getCoorY();
    }

    //-Ay + sum[i=1][n]{cyi*ci} - Dy <= 0
    constraintNumber++;
    this->constraints[constraintNumber][Ay] = -1;
    this->constraints[constraintNumber][Dy] = -1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = "<=";
    for(int i=0;i<n;i++)
    {
        this->constraints[constraintNumber][ci+i] = this->cities->at(i)->getCoorY();
    }

    //Ax + 2M Sxi - Dxi >= cxi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ax] = 1;
        this->constraints[constraintNumber][Sxi+i] = 2*this->m;
        this->constraints[constraintNumber][Dxi+i] = -1;
        this->constraints[constraintNumber][constant] = this->cities->at(i)->getCoorX();
        this->inequalities[constraintNumber] = ">=";
    }

    //Ax + 2M Sxi + Dxi <= 2M + cxi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ax] = 1;
        this->constraints[constraintNumber][Sxi+i] = 2*this->m;
        this->constraints[constraintNumber][Dxi+i] = 1;
        this->constraints[constraintNumber][constant] = 2*this->m + this->cities->at(i)->getCoorX();
        this->inequalities[constraintNumber] = "<=";
    }

    //Ax - Dxi <= cxi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ax] = 1;
        this->constraints[constraintNumber][Dxi+i] = -1;
        this->constraints[constraintNumber][constant] = this->cities->at(i)->getCoorX();
        this->inequalities[constraintNumber] = "<=";
    }

    //-Ax - Dxi <= -cxi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ax] = -1;
        this->constraints[constraintNumber][Dxi+i] = -1;
        this->constraints[constraintNumber][constant] = -this->cities->at(i)->getCoorX();
        this->inequalities[constraintNumber] = "<=";
    }

    //Ay + 2M Syi - Dyi >= cyi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ay] = 1;
        this->constraints[constraintNumber][Syi+i] = 2*this->m;
        this->constraints[constraintNumber][Dyi+i] = -1;
        this->constraints[constraintNumber][constant] = this->cities->at(i)->getCoorY();
        this->inequalities[constraintNumber] = ">=";
    }

    //Ay + 2M Syi + Dyi <= 2M + cyi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ay] = 1;
        this->constraints[constraintNumber][Syi+i] = 2*this->m;
        this->constraints[constraintNumber][Dyi+i] = 1;
        this->constraints[constraintNumber][constant] = 2*this->m + this->cities->at(i)->getCoorY();
        this->inequalities[constraintNumber] = "<=";
    }

    //Ay - Dyi <= cyi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ay] = 1;
        this->constraints[constraintNumber][Dyi+i] = -1;
        this->constraints[constraintNumber][constant] = this->cities->at(i)->getCoorY();
        this->inequalities[constraintNumber] = "<=";
    }

    //-Ay - Dyi <= -cyi
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Ay] = -1;
        this->constraints[constraintNumber][Dyi+i] = -1;
        this->constraints[constraintNumber][constant] = -this->cities->at(i)->getCoorY();
        this->inequalities[constraintNumber] = "<=";
    }

    //sum[i=1][n]{ci} = 1
    constraintNumber++;
    for(int i=0;i<n;i++)
    {
        this->constraints[constraintNumber][ci+i] = 1;
    }
    this->constraints[constraintNumber][constant] = 1;
    this->inequalities[constraintNumber] = "=";

    //Dx + Dy - Dxi - Dyi <= 0
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Dx] = 1;
        this->constraints[constraintNumber][Dy] = 1;
        this->constraints[constraintNumber][Dxi+i] = -1;
        this->constraints[constraintNumber][Dyi+i] = -1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = "<=";
    }

    //restricciones obvias

    //M-1 >= Ax >= 0
    constraintNumber++;
    this->constraints[constraintNumber][Ax] = 1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = ">=";
    constraintNumber++;
    this->constraints[constraintNumber][Ax] = 1;
    this->constraints[constraintNumber][constant] = this->m-1;
    this->inequalities[constraintNumber] = "<=";

    //M-1 >= Ay >= 0
    constraintNumber++;
    this->constraints[constraintNumber][Ay] = 1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = ">=";
    constraintNumber++;
    this->constraints[constraintNumber][Ay] = 1;
    this->constraints[constraintNumber][constant] = this->m-1;
    this->inequalities[constraintNumber] = "<=";

    //Dx >= 0; Dy >= 0
    constraintNumber++;
    this->constraints[constraintNumber][Dx] = 1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = ">=";
    constraintNumber++;
    this->constraints[constraintNumber][Dy] = 1;
    this->constraints[constraintNumber][constant] = 0;
    this->inequalities[constraintNumber] = ">=";

    //Dxi >= 0; Dyi >=0;
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Dxi+i] = 1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = ">=";
        constraintNumber++;
        this->constraints[constraintNumber][Dyi+i] = 1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = ">=";
    }

    // 1 >= Sxi >= 0; 1 >= Syi >= 0; 1 >= ci >= 0
    for(int i=0;i<n;i++)
    {
        constraintNumber++;
        this->constraints[constraintNumber][Sxi+i] = 1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = ">=";
        constraintNumber++;
        this->constraints[constraintNumber][Sxi+i] = 1;
        this->constraints[constraintNumber][constant] = 1;
        this->inequalities[constraintNumber] = "<=";
        constraintNumber++;
        this->constraints[constraintNumber][Syi+i] = 1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = ">=";
        constraintNumber++;
        this->constraints[constraintNumber][Syi+i] = 1;
        this->constraints[constraintNumber][constant] = 1;
        this->inequalities[constraintNumber] = "<=";
        constraintNumber++;
        this->constraints[constraintNumber][ci+i] = 1;
        this->constraints[constraintNumber][constant] = 0;
        this->inequalities[constraintNumber] = ">=";
        constraintNumber++;
        this->constraints[constraintNumber][ci+i] = 1;
        this->constraints[constraintNumber][constant] = 1;
        this->inequalities[constraintNumber] = "<=";
    }
}

void ConstraintsManager::setConstraints(lprec *lp)
{
    set_add_rowmode(lp, TRUE);//hace la construcción del modelo más rápido si se hace por filas

    for(int i=0;i<this->amountConstraints-1;i++)
    {
        if (this->inequalities[i] == ">=")
        {
            add_constraintex(lp,this->amountVariables-1,this->constraints[i],this->columnNumber,GE,this->constraints[i][this->amountVariables-1]);
        }else if(this->inequalities[i] == "<=")
        {
            add_constraintex(lp,this->amountVariables-1,this->constraints[i],this->columnNumber,LE,this->constraints[i][this->amountVariables-1]);
        }else if(this->inequalities[i] == "=")
        {
            add_constraintex(lp,this->amountVariables-1,this->constraints[i],this->columnNumber,EQ,this->constraints[i][this->amountVariables-1]);
        }
    }

    set_add_rowmode(lp, FALSE);//debe de "apagarse" una vez la haya terminado la costrucción del modelo

    //write_lp(lp, "model.lp");//escribe el modelo en un archivo de texto
    //this->writeConstraints();//escribir la matriz de restricciones en un archivo de texto
}

void ConstraintsManager::setColumnsNames(lprec *lp)
{
    int n = this->cities->size();

    for(int i=1,j=1;i<=n;i++,j++)
    {
        set_col_name(lp,i,QString("Dx").append(QString::number(j)).toAscii().data());
    }
    for(int i=n+1,j=1;i<=2*n;i++,j++)
    {
        set_col_name(lp,i,QString("Dy").append(QString::number(j)).toAscii().data());
    }
    for(int i=2*n+1,j=1;i<=3*n;i++,j++)
    {
        set_col_name(lp,i,QString("Sx").append(QString::number(j)).toAscii().data());
    }
    for(int i=3*n+1,j=1;i<=4*n;i++,j++)
    {
        set_col_name(lp,i,QString("Sy").append(QString::number(j)).toAscii().data());
    }
    for(int i=4*n+1,j=1;i<=5*n;i++,j++)
    {
        set_col_name(lp,i,QString("c").append(QString::number(j)).toAscii().data());
    }
    set_col_name(lp,5*n+1,"Dx");
    set_col_name(lp,5*n+2,"Dy");
    set_col_name(lp,5*n+3,"Ax");
    set_col_name(lp,5*n+4,"Ay");

    //imprimir el nombre de las columnas
    /*for(int i=1;i<=this->amountVariables;i++)
    {
        cout << "col " << i << ": " << get_col_name(lp,i) << endl;
    }*/
}

void ConstraintsManager::writeConstraints()
{
    QFile file("matriz.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {   //qDebug("algo");
        return;
    }

    QTextStream out(&file);

    int n = this->cities->size();

    for(int i=1,j=1;i<=n;i++,j++)
    {
        out << QString("Dx").append(QString::number(j)) << "\t";
    }
    for(int i=n+1,j=1;i<=2*n;i++,j++)
    {
        out << QString("Dy").append(QString::number(j)) << "\t";
    }
    for(int i=2*n+1,j=1;i<=3*n;i++,j++)
    {
        out << QString("Sx").append(QString::number(j)) << "\t";
    }
    for(int i=3*n+1,j=1;i<=4*n;i++,j++)
    {
        out << QString("Sy").append(QString::number(j)) << "\t";
    }
    for(int i=4*n+1,j=1;i<=5*n;i++,j++)
    {
        out << QString("c").append(QString::number(j)) << "\t";
    }
    out << "Dx" << "\t" << "Dy" << "\t" << "Ax" << "\t" << "Ay" << "\t" << "Rhs" << endl;

    for(int i=0;i<this->amountConstraints-1;i++)
    {
        for(int j=0;j<this->amountVariables;j++)
        {
            out << this->constraints[i][j] << "\t";
        }
        out << endl;
    }
    file.close();
}

void ConstraintsManager::setObjectiveFunction(lprec *lp)
{
    int n = this->cities->size();
    int Dx=5*n, Dy=5*n+1;
    this->constraints[this->amountConstraints-1][Dx] = 1;
    this->constraints[this->amountConstraints-1][Dy] = 1;
    set_obj_fnex(lp, this->amountVariables-1, this->constraints[this->amountConstraints-1], this->columnNumber);
    set_maxim(lp);
}

lprec* ConstraintsManager::buildModel()
{
    lprec *lp = make_lp(0,this->amountVariables-1);//-1 por que se usa una variable más para rhs

    this->buildContraints();
    this->setColumnsNames(lp);
    this->setConstraints(lp);
    this->setObjectiveFunction(lp);

    //write_lp(lp,"model.lp");

    return lp;
}
