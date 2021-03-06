<?php

namespace Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Fixture;

use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\DifferntButFirstListed\Bar as FooBarFirst;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Bar;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Foo;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\DifferntButFirstListed\Foo as BarFooLast;
use DI\Annotation\Inject;

class InjectFromVarWithTypeOfSameName
{
    /**
     * @Inject
     *
     * @var Bar
     */
    private $someBarDependency;

    /**
     * @Inject
     *
     * @var Foo
     */
    private $someFooDependency;
}

?>
-----
<?php

namespace Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Fixture;

use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\DifferntButFirstListed\Bar as FooBarFirst;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Bar;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Foo;
use Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\DifferntButFirstListed\Foo as BarFooLast;
use DI\Annotation\Inject;

class InjectFromVarWithTypeOfSameName
{
    /**
     *
     * @var Bar
     */
    private $someBarDependency;

    /**
     *
     * @var Foo
     */
    private $someFooDependency;
    public function __construct(\Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Bar $someBarDependency, \Rector\Core\Tests\Rector\Property\InjectAnnotationClassRector\Source\Foo $someFooDependency)
    {
        $this->someBarDependency = $someBarDependency;
        $this->someFooDependency = $someFooDependency;
    }
}

?>
