#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
    char nompro[10][20], mcar[20], mbar[20], busc[20];
    int cont, op, pro=0, stck[10]={0};
    float pre[10]={0}, pretot=0, totprepro[10], car=0, bar=0, prom, sumpre=0;
    do{
        printf("---Tiendita Pepe Tola---\n");
        printf("Seleccione una opcion: \n");
        printf("1. Registrar producto\n");
        printf("2. Informacion de inventario\n");
        printf("3. Producto mas caro/ mas barato\n");
        printf("4. Precio promedio de inventario\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d",&op);
        switch (op){
        case 1:
        char nnom[20];
        int rep=0;
        if (pro >= 10) {
                printf("\nEl inventario esta lleno.\n");
                break; 
            }
            printf("---Registro de producto---\n");
            printf("Nombre: ");
            scanf("%s", &nnom);
            for (int i = 0; i < pro; i++){
                if(strcmp(nnom, nompro[i])==0){
                    rep=1;
                    break;
                }}
            if (rep==1){
                printf("\nProducto ya registrado");
                break;}
            else{
                strcpy(nompro[pro], nnom);}
            int valpre=0;
                printf("Precio: $");
            valpre=scanf("%f", &pre[pro]);
            while (pre[pro]<0 || valpre!=1){
                while ((getchar())!='\n');
                printf("Precio invalido. Ingresa nuevamente: $");
                scanf("%f", &pre[pro]);}
            int vals=0;
                printf("Stock: ");
            vals=scanf("%d", &stck[pro]);
            while (stck[pro]<0 || vals!=1){
                while ((getchar())!='\n');
                printf("Stock invalido. Ingresa nuevamente: ");
                scanf("%d", &stck[pro]);}
            if (pro==0){
                car=pre[pro];
                bar=pre[pro];}
            if (pre[pro]<bar){
                strcpy(mbar, nompro[pro]);
                bar=pre[pro];}
            if (pre[pro]>car){
                strcpy(mcar, nompro[pro]);
                car=pre[pro];}
            sumpre+=pre[pro];
            totprepro[pro]=(float)pre[pro]*stck[pro];
            pretot+=totprepro[pro];
            pro++;
            break;
            case 2: 
            if(pro==0){
                printf("Sin productos registrados");
            }
            else{
                printf("N°\t\tNombre del producto\t\tPrecio\t\tStock\t\tValor total por producto\n");
            for (int i = 0; i < pro; i++)
            {
                printf("%d\t\t%s\t\t\t\t$%.2f\t\t%d\t\t$%.2f\n", i, nompro[i], pre[i], stck[i], totprepro[i]);
            }
            printf("Total del inventario: \t\t\t\t$%.2f", pretot);
            }
            break;
            case 3:
            if (pro==0){
                printf("Sin productos registrados");}
            else if(pro==1){
                printf("1 solo producto registrado: \n");
                for (int i = 0; i < pro; i++)
                {
                    printf("%s\t\t$%.2f\n", nompro[i], pre[i]);
                }}
            else if(car==bar){
                printf("Productos de igual precio\n");
                printf("Nombre\t\tPrecio\n");
                for (int i = 0; i < pro; i++)
                {
                    printf("%s\t\t$%.2f\n", nompro[i], pre[i]);
                }}
            else{
                printf("Producto(s) mas caro(s): \n");
                printf("Nombre\t\tPrecio\n");
                for (int i = 0; i < pro; i++)
                {
                    if(pre[i]==car){
                        printf("%s\t\t$%.2f\n", nompro[i], pre[i]);
                    }
                }
                printf("\nProducto(s) mas barato(s): \n");
                printf("Nombre\t\tPrecio\n");
                for (int i = 0; i < pro; i++)
                {
                    if(pre[i]==bar){
                        printf("%s\t\t$%.2f\n", nompro[i], pre[i]);
                    }
                } 
            }
            break;
            case 4:
            if(pro==0){
                printf("Sin productos registrados");
            }
            else{
                prom=(float)sumpre/pro;
                printf("N°\t\tNombre del producto\t\tPrecio\t\tStock\t\tValor total por producto\n");
                for (int i = 0; i < pro; i++)
                {
                    printf("%d\t\t%s\t\t\t\t$%.2f\t\t%d\t\t$%.2f\n", i, nompro[i], pre[i], stck[i], totprepro[i]);
                }
                printf("Promedio de precios: \t\t\t\t$%.2f", prom);
            }
            break;
            case 5:
            if(pro==0){
                printf("Sin productos registrados");
            }
            else{
            int enc=0;
            printf("---Buscar producto---\n");
            printf("Ingrese el nombre del producto: ");
            scanf("%s", &busc);
            for (int i = 0; i < pro; i++)
            {
                if (strcmp(busc, nompro[i])==0){
                printf("\nProducto encotrado\n\n");
                printf("Nombre del producto\t\tPrecio\t\tStock\t\tValor total por producto\n");
                printf("%s\t\t\t\t$%.2f\t\t%d\t\t$%.2f\n", nompro[i], pre[i], stck[i], totprepro[i]);
                enc=1;}
            }
             if (enc==0){
                printf("\nProducto no existente o nombre incorrecto");
            }}
            break;
            case 6:
            return 0;
        default:
        printf("\nOpcion no valida");
            break;
        }
        printf("\nDesea escoger otra opcion? 1.Si 2.No\n");
        printf(">> ");
        scanf("%d", &cont);
        while(cont!=1 && cont!=2){
            printf("Opcion no valida. Ingrese nuevamente\n");
            printf(">> ");
            scanf("%d", &cont);
        }
    }while(cont==1);
    return 0;
}