```yaml
width
  - auto
  - length
    - integer:unit
  - %
  - inherit
```
```yaml
AttributeDef:
  -name: "width"
  -values:
    -auto:
      - type: string
    -length:
      - type: integer
      - unit:
          - em
          - ex
          - %
          - px
          - cm
          - mm
          - in
          - pt
          - pc
          - ch
          - rem
          - vh
          - vw
          - vmin(vm)
          - vmax
    -%:
    -inherit:
      - type: string
```

1. 定义属性
   - 定义属性名称
   - 定义属性值
     - 属性名称
     - 属性解析器
