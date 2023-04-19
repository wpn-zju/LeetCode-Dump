select product_name, o.product_id, order_id, order_date
from Orders o left join Products p
using(product_id)
where (product_id, order_date) in
(
    select product_id, max(order_date) order_date
    from Orders
    group by product_id
)
order by product_name, product_id, order_id