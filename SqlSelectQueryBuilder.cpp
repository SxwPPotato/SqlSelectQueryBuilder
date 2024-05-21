#include <iostream>
#include "sql_query_builder.h"
#include <vector>

int main(){

    SqlSelectQueryBuilder query_builder;
    query_builder.AddColum("name").AddColum("phone");
    query_builder.AddFrom("students");
    //query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::map<std::string, std::string> mp = {
        {"id", "42"}, {"name", "John"}
    };
    query_builder.AddWhere(mp);

    std::cout << query_builder.BuildQuery();
    std::cout << std::endl;

    AdvancedSqlSelectQueryBuilder query_builders;
    query_builders.AddColumns({ "name", "phone" });
    query_builders.AddFrom("students");
    query_builders.MoreLess("id", "42", '>');

    std::cout << query_builders.BuildQuery();
    
}